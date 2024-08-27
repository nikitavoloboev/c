#include <iostream>
#include <vector>

template <typename T>
concept Iterable = requires(T a) {
  a.begin();
  a.end();
};

template <typename T> void Log(const T &data) {
  if constexpr (Iterable<T> && !std::is_same_v<std::string, T>) {
    std::cout << "[";
    for (const auto &d : data) {
      Log(d);
    }
    std::cout << "]" << std::endl;
  } else {
    std::cout << data << std::endl;
  }
}

#define MYLOG(var)                                                             \
  std::cout << #var << ": ";                                                   \
  Log(var);

struct Foo {};

int main() {
  std::vector<std::string> vec{"dog", "cat"};
  std::vector<std::vector<std::string>> A{{"Hello", "World"}, {"Foo", "Bar"}};
  MYLOG(A);
}

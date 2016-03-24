#include <string>
#include <sstream>

#ifndef HELLOWORKTILE_CORE_JNI_STRING_UTILS_ANDROID_H_
#define HELLOWORKTILE_CORE_JNI_STRING_UTILS_ANDROID_H_

namespace std {

template<typename T>
std::string to_string(T value) {
  std::ostringstream os;
  os << value;
  return os.str();
}

} // namespace std

#endif //enddef HELLOWORKTILE_CORE_JNI_STRING_UTILS_ANDROID_H_

#include <jni.h>

#include "user.h"

extern "C" {

JNIEXPORT jlong JNICALL
Java_com_worktilecore_User_nativeCreateUser(JNIEnv *env, jobject instance) {
  worktile::User* user = new worktile::User();
  return reinterpret_cast<jlong>(user);
}

JNIEXPORT void JNICALL
Java_com_worktilecore_User_nativeDisposeUser(JNIEnv *env, jobject instance, jlong handler) {
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  WTC_SAFE_DELETE(user);
}

JNIEXPORT void JNICALL
Java_com_worktilecore_User_nativeInitWithJson(JNIEnv *env, jobject instance, jlong handler,
                                              jstring json_) {
  const char *json = env->GetStringUTFChars(json_, 0);
  std::string json_str = json;

  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  user->InitWithJsonOrDie(json_str);

  env->ReleaseStringUTFChars(json_, json);
}

JNIEXPORT jstring JNICALL
Java_com_worktilecore_User_nativeGetUid(JNIEnv *env, jobject instance, jlong handler) {
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  std::string uid = user->uid();

  return env->NewStringUTF(uid.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_worktilecore_User_nativeGetUsername(JNIEnv *env, jobject instance, jlong handler) {
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  std::string username = user->username();

  return env->NewStringUTF(username.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_worktilecore_User_nativeGetDisplayName(JNIEnv *env, jobject instance, jlong handler) {
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  std::string display_name = user->display_name();

  return env->NewStringUTF(display_name.c_str());
}

JNIEXPORT void JNICALL
Java_com_worktilecore_User_nativeSetDisplayName(JNIEnv *env, jobject instance, jlong handler,
                                                jstring displayName_) {
  const char *displayName = env->GetStringUTFChars(displayName_, 0);

  std::string display_name_str = displayName;
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  user->set_display_name(display_name_str);

  env->ReleaseStringUTFChars(displayName_, displayName);
}

JNIEXPORT jint JNICALL
Java_com_worktilecore_User_nativeGetStatus(JNIEnv *env, jobject instance, jlong handler) {
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  return static_cast<jint>(user->status());
}

JNIEXPORT jstring JNICALL
Java_com_worktilecore_User_nativeStatusDescription(JNIEnv *env, jobject instance, jlong handler) {
  worktile::User* user = reinterpret_cast<worktile::User*>(handler);
  std::string desc = user->StatusDescription();

  return env->NewStringUTF(desc.c_str());
}

}
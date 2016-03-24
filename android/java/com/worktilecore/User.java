package com.worktilecore;

import android.support.annotation.IntDef;
import android.support.annotation.NonNull;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * Worktile 的用户对象
 *
 * 注释1: 该文件代码风格遵循 Android Code Style for Contributors (https://source.android.com/source/code-style.html)
 */
public class User extends CoreObject {

    @IntDef ({NORMAL, INVITED, PENDING})
    @Retention(RetentionPolicy.SOURCE)
    public @interface Status{}

    public static final int NORMAL  = 0;
    public static final int INVITED = 1;
    public static final int PENDING = 2;


    /**
     * 通过 JSON 来初始化用户对象
     * @param json 对应的 JSON
     */
    public User(String json) {
        mNativeHandler = nativeCreateUser();
        nativeInitWithJson(mNativeHandler, json);
    }


    /**
     * 销毁 User 对象
     */
    @Override
    public void dispose() {
        nativeDisposeUser(mNativeHandler);
        mNativeHandler = JniHelper.NULLPTR;
    }

    /**
     * 获取用户的 UID
     * @return UID
     */
    public String getUid() {
        if (mNativeHandler != JniHelper.NULLPTR) {
            return nativeGetUid(mNativeHandler);
        }
        return JniHelper.handleNullptrReturnString();
    }

    /**
     * 获取用户的用户名
     * @return 用户名
     */
    public String getUsername() {
        if (mNativeHandler != JniHelper.NULLPTR) {
            return nativeGetUsername(mNativeHandler);
        }
        return JniHelper.handleNullptrReturnString();
    }

    /**
     * 获取用户的显示名称
     * @return 显示的名称
     */
    public String getDisplayName() {
        if (mNativeHandler != JniHelper.NULLPTR) {
            return nativeGetDisplayName(mNativeHandler);
        }
        return JniHelper.handleNullptrReturnString();
    }

    /**
     * 设置用户显示的名称
     * @param displayName 显示的名称
     */
    public void setDisplayName(@NonNull String displayName) {
        if (mNativeHandler != JniHelper.NULLPTR) {
            nativeSetDisplayName(mNativeHandler, displayName);
        }
    }

    /**
     * 获取用户的状态
     * @return 用户的状态
     */
    @Status
    public int getStatus() {
        if (mNativeHandler != JniHelper.NULLPTR) {
            return statusFromInt(nativeGetStatus(mNativeHandler));
        }
        return NORMAL;
    }

    /**
     * 获取用户状态描述
     * @return 用户状态的描述文字
     */
    public String statusDescription() {
        if (mNativeHandler != JniHelper.NULLPTR) {
            return nativeStatusDescription(mNativeHandler);
        }
        return JniHelper.handleNullptrReturnString();
    }


    private @Status int statusFromInt(int val) {
        switch (val) {
            case 0: return NORMAL;
            case 1: return INVITED;
            case 2: return PENDING;
        }
        return NORMAL;
    }

    private native long nativeCreateUser();

    private native void nativeDisposeUser(long handler);

    private native void nativeInitWithJson(long handler, @NonNull String json);

    @NonNull
    private native String nativeGetUid(long handler);

    @NonNull
    private native String nativeGetUsername(long handler);

    @NonNull
    private native String nativeGetDisplayName(long handler);

    private native void nativeSetDisplayName(long handler, @NonNull String displayName);

    private native int nativeGetStatus(long handler);

    private native String nativeStatusDescription(long handler);
}

package com.worktilecore;

/**
 * 与 core 相关的 C++ 的封装应当继承自该类
 */
public abstract class CoreObject {

    /**
     * 代表了 C++ 的内存地址
     */
    protected volatile long mNativeHandler = JniHelper.NULLPTR;

    /**
     * 手动释放 C++ 内存
     */
    public abstract void dispose();
}

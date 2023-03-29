// sudo apt-get install gcc-multilib g++-multilib

#include <jni.h>
#include <stdio.h>
#include "javaJNI.h"

JNIEXPORT void JNICALL Java_javajni_JavaJNI_nativePrint( JNIEnv *env, jobject obj )
{
    printf("\nПогладь КОТА из C\n");
}

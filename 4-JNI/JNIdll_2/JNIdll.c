#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include "javaJNI.h"

JNIEXPORT jstring JNICALL Java_javajni_JavaJNI_nativePrint( JNIEnv *env, jobject obj, jint i )
{
    char* buf = " А так же из Javы "; 
    printf( "\nПогладь КОТА из C\n" );
    sleep(i*1);
    return (*env)->NewStringUTF( env, buf );
}
JNIEXPORT void JNICALL Java_javajni_JavaJNI_nativeChange( JNIEnv *env, jobject obj, jint i )
{
  jstring jstr;
  jfieldID fid;
  jclass oClass = (*env)->GetObjectClass( env, obj );
  fid = (*env)->GetStaticFieldID( env, oClass, "s", "Ljava/lang/String;" );
  jstr =(*env)->NewStringUTF( env, " Ещё!!!" );
  (*env)->SetStaticObjectField( env, oClass, fid, jstr );
  sleep( i*1 );
}
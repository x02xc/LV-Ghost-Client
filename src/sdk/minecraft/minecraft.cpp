#include "minecraft.h"
#include "./classes/classes.h"
#include <iostream>

c_minecraft::c_minecraft(jobject object_in) : c_jobject(object_in) {
	
};

c_minecraft c_minecraft::get_minecraft() {
    static jmethodID get_minecraft_method = jvm::env->GetStaticMethodID(classes::minecraft_class, "u", "()Ldbl;");
    jobject result = jvm::env->CallStaticObjectMethod(classes::minecraft_class, get_minecraft_method);

	return c_minecraft(result);
};

c_entity c_minecraft::getLocalPlayer() {
	static jfieldID player = jvm::env->GetFieldID(classes::minecraft_class, "i", "Ldpy;");

	return c_entity(jvm::env->GetObjectField(c_minecraft::get_minecraft().cached_object, player));
};
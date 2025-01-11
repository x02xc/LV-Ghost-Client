#include "entity.h"
#include "classes/classes.h"

c_entity::c_entity(jobject object_in) : c_jobject(object_in) {
	
}
//void c_entity::set_sprinting(bool state) {
//	static jmethodID set_sprinting_method = jvm::env->GetMethodID(classes::entity_class, "f", "(Z)V");
//
//	jvm::env->CallVoidMethod(this->cached_object, set_sprinting_method, state);
//}
//
//bool c_entity::is_sprinting() {
//	static jmethodID is_sprinting_method = jvm::env->GetMethodID(classes::entity_class, "bi", "()Z");
//	return jvm::env->CallBooleanMethod(this->cached_object, is_sprinting_method);
//}
#include "classes.h"
#include "../../jvm.h"

void classes::load() {
	minecraft_class = jvm::env->FindClass("dbl");

	entity_class = jvm::env->FindClass("dpy");
};
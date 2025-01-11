#pragma once
#include "entity.h"

class c_minecraft : public c_jobject {
public:
    c_minecraft(jobject object_in);

    static c_minecraft get_minecraft();
	static c_entity getLocalPlayer();
};

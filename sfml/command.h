#pragma once
#include "ball.h"
#include <iostream>

class Command {
public:
	virtual ~Command() {}
	virtual void execute(Ball& ball) = 0;

};
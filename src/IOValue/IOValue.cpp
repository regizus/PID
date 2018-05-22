/*
 * IOValue.cpp
 *
 *  Created on: 14 kwi 2018
 *      Author: marcin
 */

#include "IOValue.h"
#include <cmath>

namespace pid_reg {

void IOValue::setRange(double &RangeLowerLimit, double &RangeUpperLimit)
{
	if(RangeLowerLimit <= RangeUpperLimit)
	{
		this->RangeLower = RangeLowerLimit;
		this->RangeUpper = RangeUpperLimit;
	}
	else // mismatched range limits
	{
		#ifdef useExceptionThrowing
			// THROW EXCEPTION HERE
		#endif
		// *********************************
		#ifndef useExceptionThrowing // correct limits by switching places "upper" and "lower"
			this->RangeLower = RangeUpperLimit;
			this->RangeUpper = RangeLowerLimit;
		#endif
	}

	this->RangeWidth = std::abs(RangeUpperLimit-RangeLowerLimit);

	this->updateValue(Value);
}

void IOValue::getRange(double &RangeLowerLimit, double &RangeUpperLimit)
{
	RangeLowerLimit = this->RangeLower;
	RangeUpperLimit = this->RangeUpper;
}

void IOValue::updateValue(double &CurrentValue)
{
	if((CurrentValue <= this->RangeUpper) && (CurrentValue >= this->RangeLower))
		this->Value = CurrentValue;
	else if((CurrentValue > this->RangeUpper))
		this->Value = this->RangeUpper;
	else
		this->Value = this->RangeLower;
}

double IOValue::ShowValue()
{
	return this->Value;
}

void IOValue::ShowValue(double &CurrentValue)
{
	CurrentValue = this->Value;
}

IOValue::IOValue(double CurrentValue, double RangeLowerLimit, double RangeUpperLimit)
{
	this->Value = CurrentValue;
	setRange(RangeLowerLimit, RangeUpperLimit);
}

IOValue::~IOValue() {
	// TODO Auto-generated destructor stub
}

} /* namespace pid_reg */

/*
 * IOValue.cpp
 *
 *  Created on: 14 kwi 2018
 *      Author: marcin
 */

#include "IOValue.h"
#include <cmath>

namespace pid_reg {

void IOValue::setRange(double &setRangeLowerLimit, double &setRangeUpperLimit)
{
	if(setRangeLowerLimit <= setRangeUpperLimit)
	{
		this->RangeLowerLimit = setRangeLowerLimit;
		this->RangeUpperLimit = setRangeUpperLimit;
	}
	else // mismatched range limits
	{
		#ifdef useExceptionThrowing
			// THROW EXCEPTION HERE
		#endif
		// *********************************
		#ifndef useExceptionThrowing // correct limits by switching places "upper" and "lower"
			this->RangeLowerLimit = setRangeUpperLimit;
			this->RangeUpperLimit = setRangeLowerLimit;
		#endif
	}

	this->RangeWidth = std::abs(setRangeUpperLimit-setRangeLowerLimit);

	this->updateValue(Value);
}

void IOValue::getRange(double &getRangeLowerLimit, double &getRangeUpperLimit)
{
	getRangeLowerLimit = this->RangeLowerLimit;
	getRangeUpperLimit = this->RangeUpperLimit;
}

void IOValue::updateValue(double &CurrentValue)
{
	if((CurrentValue <= this->RangeUpperLimit) && (CurrentValue >= this->RangeLowerLimit))
		this->Value = CurrentValue;
	else if((CurrentValue > this->RangeUpperLimit))
		this->Value = this->RangeUpperLimit;
	else
		this->Value = this->RangeLowerLimit;
}

double IOValue::ShowValue()
{
	return this->Value;
}

void IOValue::ShowValue(double &CurrentValue)
{
	CurrentValue = this->Value;
}

IOValue::IOValue(double CurrentValue = 0, double RangeLowerLimit = 0, double RangeUpperLimit = 0)
{
	this->Value = CurrentValue;
	setRange(RangeLowerLimit, RangeUpperLimit);
}

IOValue::~IOValue() {
	// TODO Auto-generated destructor stub
}

} /* namespace pid_reg */

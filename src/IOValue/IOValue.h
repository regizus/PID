/*
 * IOValue.h
 *
 *  Created on: 14 kwi 2018
 *      Author: marcin
 */

#ifndef IOVALUE_IOVALUE_H_
#define IOVALUE_IOVALUE_H_

namespace pid_reg {

class IOValue {
public:
	IOValue(double CurrentValue, double RangeLowerLimit, double RangeUpperLimit);
	virtual ~IOValue();
	void setRange(double &RangeLowerLimit, double &RangeUpperLimit);
	void getRange(double &RangeLowerLimit, double &RangeUpperLimit);
	void updateValue(double &CurrentValue);
	double ShowValue();
	void ShowValue(double &CurrentValue);
private:
	double Value;
	double RangeUpper;
	double RangeLower;
	double RangeWidth;
};

} /* namespace std */

#endif /* IOVALUE_IOVALUE_H_ */

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
	void setRange(double &setRangeLowerLimit, double &setRangeUpperLimit);
	void getRange(double &getRangeLowerLimit, double &getRangeUpperLimit);
	void updateValue(double &CurrentValue);
	double ShowValue();
	void ShowValue(double &CurrentValue);
private:
	double Value;
	double RangeUpperLimit;
	double RangeLowerLimit;
	double RangeWidth;
};

} /* namespace std */

#endif /* IOVALUE_IOVALUE_H_ */

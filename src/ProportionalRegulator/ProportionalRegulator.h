/*
 * ProportionalRegulator.h
 *
 *  Created on: 14 kwi 2018
 *      Author: marcin
 */
#include "../IOValue/IOValue.h"

#ifndef PROPORTIONALREGULATOR_H_
#define PROPORTIONALREGULATOR_H_


namespace pid_reg {

class ProportionalRegulator {
public:
	ProportionalRegulator();
	virtual ~ProportionalRegulator();
	bool invertedOperation;
	IOValue SetPointValue();
	IOValue ProcessValue();
	double Deviation;
	IOValue ControlValue();



};

} /* namespace std */

#endif /* PROPORTIONALREGULATOR_H_ */

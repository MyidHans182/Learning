#ifndef CONTROLLER_H
#define CONTROLLER_H

void updateStateVariables();
void runHipTrajectoryAndPID();
void calculateLQR();
void applyReceivedCommands();

#endif
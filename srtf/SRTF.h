#ifndef SRTF_H
#define SRTF_H

#include "PriorityQueue.h"

void getValues(PriorityQueue q);
void computeWaitingTime(PriorityQueue ready_q, PriorityQueue waiting_q,
                        PriorityQueue result_q);
void displayTable(PriorityQueue q);

#endif
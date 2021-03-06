/*
 * timing.h
 *
 *  Created on: 10 Nov 2015
 *      Author: Florian Geyer
 *
 */
 
#ifndef TIMING_H_
#define TIMING_H_

#include <chrono>
#include <functional>

std::chrono::steady_clock::time_point tmr_t1, tmr_t2;
#define TIMER_START(doit)	if (doit) { tmr_t1 = std::chrono::steady_clock::now(); }
#define TIMER_STOP(doit)	if (doit) { tmr_t2 = std::chrono::steady_clock::now(); }
#define TIMER_RESULT(vartype)	chrono::duration_cast<chrono::vartype>(tmr_t2 - tmr_t1).count()
#define TIMER_OUTPUT_MS_F(text, doit)	if (doit) { std::cout << text << ": " << TIMER_RESULT(nanoseconds)/1000000.0f << "ms" << std::endl; }
#define TIMER_OUTPUT_US_F(text, doit)	if (doit) { std::cout << text << ": " << TIMER_RESULT(nanoseconds)/1000.0f << "us" << std::endl; }
#define TIMER_OUTPUT_MS(text, doit)	if (doit) { std::cout << text << ": " << TIMER_RESULT(milliseconds) << "ms" << std::endl; }
#define TIMER_OUTPUT_US(text, doit)	if (doit) { std::cout << text << ": " << TIMER_RESULT(microseconds) << "us" << std::endl; }
#define TIMER_OUTPUT_NS(text, doit)	if (doit) { std::cout << text << ": " << TIMER_RESULT(nanoseconds) << "ns" << std::endl; }

#endif
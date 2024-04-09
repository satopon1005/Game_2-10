#include "DxLib.h"
#include "CountTime.h"
#include "../Common.h"

CountTime::CountTime()
{
	m_start_time = 0;
	m_end_time = 0;
	m_now_time = 0;

	m_minutes = 0;
	m_seconds = 0;

	m_count_time_flag = false;

	m_display_font_handle[0] = CreateFontToHandle(NULL, 40, 3);
	m_display_font_handle[1] = CreateFontToHandle(NULL, 100, 3);
}

CountTime::~CountTime()
{
	DeleteFontToHandle(m_display_font_handle[0]);
}

void CountTime::InitCountTime(int minutes, int seconds)
{
	m_start_time = 0;
	m_end_time = 0;
	m_now_time = 0;

	m_end_time += minutes * 60;
	m_end_time += seconds;

	m_end_time *= 1000;

	m_minutes = minutes;
	m_seconds = seconds;

	m_count_time_flag = false;
}

void CountTime::StartCountTime()
{
	m_start_time = GetNowCount();
	m_count_time_flag = true;
}

void CountTime::StepCountTimeDown()
{
	m_now_time = GetNowCount();

	int elapsed_time = m_now_time - m_start_time;

	if (elapsed_time >= 1000) {

		m_start_time = m_now_time;
		m_seconds--;

		if (m_seconds < 0) {
			m_minutes--;
			m_seconds = 59;
		}
	}
}

bool CountTime::CheckEndCountTimeDown()
{
	if (m_minutes == 0 && m_seconds == 0) {
		m_count_time_flag = false;
		return true;
	}
	return false;
}

void CountTime::DrawCountTime()
{
	DrawBox(SCREEN_SIZE_X / 2 - 60, 0,
		SCREEN_SIZE_X / 2 - 60 + 140, 40,
		GetColor(0, 0, 0), false);

	DrawFormatStringToHandle(SCREEN_SIZE_X / 2 - 40, 0,
		GetColor(0, 0, 0),
		m_display_font_handle[0],
		"%02d:%02d", m_minutes, m_seconds);
}

void CountTime::DrawCountTimeStart()
{
	DrawFormatStringToHandle(SCREEN_SIZE_X / 2 - 25,
		SCREEN_SIZE_Y / 2 - 50,
		GetColor(0, 0, 0),
		m_display_font_handle[1],
		"%d", m_seconds);
}
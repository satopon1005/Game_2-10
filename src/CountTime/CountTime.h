#pragma once

class CountTime
{
private:
	int m_start_time;
	int m_end_time;
	int m_now_time;

	int m_minutes;
	int m_seconds;

	bool m_count_time_flag;

	int m_display_font_handle[2];

public:
	CountTime();
	~CountTime();

	void InitCountTime(int minutes = 0, int seconds = 0);
	void StartCountTime();

	void StepCountTimeDown();
	bool CheckEndCountTimeDown();

	void DrawCountTime();
	void DrawCountTimeStart();

	int GetMinutes() { return m_minutes; }
	int GetSeconds() { return m_seconds; }
	bool GetCountTimeFlag() { return m_count_time_flag; }

	int GetStartTime() { return m_start_time; }
	int GetEndTime() { return m_end_time; }
	int GetNowTime() { return m_now_time; }
};
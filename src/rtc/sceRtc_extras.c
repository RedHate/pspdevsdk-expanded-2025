/* Set year field(1-9999) */
static __inline__ int sceRtcSetYear(ScePspDateTime *pTime, int year)
{
	if (year<1 || year>9999) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->year = year;
	return (0);
}

/* Set month field(1-12) */
static __inline__ int sceRtcSetMonth(ScePspDateTime *pTime, int month)
{
	if (month<1 || month>12) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->month = month;
	return (0);
}

/* Set day field(1-31) */
static __inline__ int sceRtcSetDay(ScePspDateTime *pTime, int day)
{
	if (day<1 || day>31) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->day = day;
	return (0);
}

/* Set hour field(0-23) */
static __inline__ int sceRtcSetHour(ScePspDateTime *pTime, int hour)
{
	if (hour<0 || hour>23) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->hour = hour;
	return (0);
}

/* Set minute field(0-59) */
static __inline__ int sceRtcSetMinute(ScePspDateTime *pTime, int minute)
{
	if (minute<0 || minute>59) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->minute = minute;
	return (0);
}

/* Set second field(0-59) */
static __inline__ int sceRtcSetSecond(ScePspDateTime *pTime, int second)
{
	if (second<0 || second>59) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->second = second;
	return (0);
}

/* Set microsecond field(0-999999) */
static __inline__ int sceRtcSetMicrosecond(ScePspDateTime *pTime, int microsecond)
{
	if (microsecond<0 || microsecond>999999) {
		return (PSP_ERROR_INVALID_ARG);
	}
	pTime->microsecond = microsecond;
	return (0);
}

/* Get year field(0-9999) */
static __inline__ int sceRtcGetYear(const ScePspDateTime *pTime)
{
	return (pTime->year);
}

/* Get month field(1-12) */
static __inline__ int sceRtcGetMonth(const ScePspDateTime *pTime)
{
	return (pTime->month);
}

/* Get day field(1-31) */
static __inline__ int sceRtcGetDay(const ScePspDateTime *pTime)
{
	return (pTime->day);
}

/* Get hour field(0-23) */
static __inline__ int sceRtcGetHour(const ScePspDateTime *pTime)
{
	return (pTime->hour);
}

/* Get minute field(0-59) */
static __inline__ int sceRtcGetMinute(const ScePspDateTime *pTime)
{
	return (pTime->minute);
}

/* Get second field(0-59) */
static __inline__ int sceRtcGetSecond(const ScePspDateTime *pTime)
{
	return (pTime->second);
}

/* Get microsecond field(0-999999) */
static __inline__ int sceRtcGetMicrosecond(const ScePspDateTime *pTime)
{
	return (pTime->microsecond);
}

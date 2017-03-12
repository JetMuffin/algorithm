import time
f = [1972, 1981, 1982, 1983, 1985, 1992, 1993, 1994, 1997, 2012, 2015]
g = [1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979, 1987, 1989, 1990, 1995, 1998, 2005, 2008, 2016]

while True:
	try:
		s1 = raw_input()
		s2 = raw_input()

		a1 = time.strptime(s1.strip(), "%Y-%m-%d %H:%M:%S")
		a2 = time.strptime(s2.strip(), "%Y-%m-%d %H:%M:%S")

		if(a1.tm_mon < 7):
			six_year_start = a1.tm_year
		else:
			six_year_start = a1.tm_year + 1

		if(a2.tm_mon > 6):
			six_year_end = a2.tm_year
		else:
			six_year_end = a2.tm_year - 1

		tw_year_start = a1.tm_year
		tw_year_end = a2.tm_year - 1

		# print six_year_start, six_year_end
		# print tw_year_start, tw_year_end

		t1 = time.mktime(a1)
		t2 = time.mktime(a2)

		ans = t2 - t1
		for x in xrange(six_year_start, six_year_end + 1):
			if(x in f):
				ans = ans + 1

		for x in xrange(tw_year_start, tw_year_end + 1):
			if(x in g):
				ans = ans + 1

		print int(ans)

	except:
		break
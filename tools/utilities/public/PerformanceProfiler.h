#pragma once

namespace performance_profiler
{

	struct PerformaceStats
	{
		double vrm_comm_accumulated_time{ 0 };
		double cigi_comm_accumulated_time{ 0 };
		double bridge_accumulated_time{ 0 };
		double alltime_accumulated_time{ 0 };

		double vrm_comm_current_time{ 0 };
		double cigi_comm_current_time{ 0 };
		double bridge_current_time{ 0 };
		double alltime_current_time{ 0 };

		long long frame_count{ 0 };
	};

	inline PerformaceStats stats;

}


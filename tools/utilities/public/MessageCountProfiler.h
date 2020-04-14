#pragma once

namespace cigi_stats
{

	struct CigiMessagesStats
	{
		long long cycle_count{ 0 };
		long long overall_messages{ 0 };
		long local_msg_count{ 0 };
		long max_count{ 0 };

		long long overall_packet_size {0};
		int max_packet_size {0};
	};

	inline CigiMessagesStats stats;

}

namespace vrm_stats
{

	struct VRMMessagesStats
	{
		long long cycle_count{ 0 };
		long long overall_messages{ 0 };
		long local_msg_count{ 0 };
		long max_count{ 0 };
	};

	inline VRMMessagesStats stats;

}


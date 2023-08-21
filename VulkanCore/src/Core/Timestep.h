#pragma once

namespace VulkanCore {

	class Timestep
	{
	public:
		Timestep(){}
		Timestep(float time);

		inline float GetSeconds() const { return m_Time; }
		inline float GetMilliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time = 0.0f;
	};
}

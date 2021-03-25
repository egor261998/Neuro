#pragma once

namespace neuro
{
	class CNeuron;

	/** ��� ����� ����� ����� ��������� */
	class CNeuroWeight
	{
	public:
		/** ��������� �� ������� �� ������� ������ */
		const CNeuron* pInputNeuron;

		/** ��������� �� �������� �� ������� ������ */
		const CNeuron* pOutputNeuron;

		/** �������� ���� ����� */
		DOUBLE fWeight = 0.f;

		/**
		 * ������� ����� ����� ����� ���������.
		 * @param inputNeuron - ������� ������.
		 * @param outputNeuron - �������� ������.
		 */
		CNeuroWeight(
			_In_ const CNeuron& inputNeuron,
			_In_ const CNeuron& outputNeuron) noexcept
		{
			this->pInputNeuron = &inputNeuron;
			this->pOutputNeuron = &outputNeuron;
		}
	};
}

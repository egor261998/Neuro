#pragma once

#include "CNeuron.h"

namespace neuro
{
	/** ��������� ���� */
	class CNeuro
	{
	private:
		/** ������������� */
		class Lock {
		public:
			Lock(std::mutex& mutex) : lock{ mutex } {};
		private:
			std::scoped_lock<std::mutex> lock;
		};

		/** ������ ������������� */
		std::mutex mutex;

		/** ���� �������� */
		std::list<std::pair<std::list<CNeuron>, BOOL>> layers;

		/** ���� ����� �������� */
		std::list<CNeuroWeight> neuronWeights;

		/** ������� ��������� ������� ��-��������� */
		fMathFunc fActivation;

		/** ������� ������������� ������� ��-��������� */
		fMathFunc fCorrercion;

		/** ����������� �������� ��������� ���� */
		DOUBLE fKf;
	public:
		/**
		 * ����������� ��������� ����.
		 * @param fCorrercion - ������� ��������� ������� ��-���������.
		 * @param fCorrercion - ������� ������������� ������� ��-���������.
		 * @param fKf - ����������� �������� ��������� ����.
		 */
		CNeuro(
			_In_ fMathFunc fActivation,
			_In_ fMathFunc fCorrercion,
			_In_ DOUBLE fKf);

		/**
		 * �������� ���� ��������.
		 * @param szCountNeuron - ���������� �������� � ����.
		 * @param bShift - ������� ������� ������� ��������. ���� true �� ��������� ������ ����� �������� ��������. 
		 * @param fCorrercion - ������� ��������� ����� ��� �������� ����.
		 * @param fCorrercion - ������� ������������� ����� ��� �������� ����.
		 * @return - ���������� ����� ����.
		 */
		size_t addLayer(
			_In_ size_t szCountNeuron,
			_In_ BOOL bShift = false,
			_In_opt_ fMathFunc fActivation = nullptr,
			_In_opt_ fMathFunc fCorrercion = nullptr);
		
		/**
		 * ������������� ��������� �������� ��� ����� �����.
		 * @param fMin - ����������� ��������.
		 * @param fMax - ������������ ��������.
		 */
		VOID randomWeight(
			_In_ DOUBLE fMin = 0.f,
			_In_ DOUBLE fMax = 0.f);

		/**
		 * �������� �������� ����� ��������� ����.
		 * @param input - ������� ��������.
		 * @return - ��������� �������.
		 */
		std::vector<DOUBLE> calc(
			_In_ std::vector<DOUBLE> input);

		/**
		 * �������� ������ ��������� ����.
		 * @param input - ������� ��������.
		 * @param bCorrect - ������� ������������� ����� ����� ����� ��������� ������.
		 * @return - ���������� �������� �� ����������.
		 */
		std::vector<DOUBLE> calcError(
			_In_ std::vector<DOUBLE> input,
			_In_ BOOL bCorrect = false);

		/**
		 * ��������������� ���� ����� ������ �� ������.
		 * @param pLock - ������ �������������.
		 */
		VOID correctWeight(
			_In_opt_ Lock *pLock = nullptr);

		/**
		 * �������� ������ ��������������� ������ �������.
		 * @return - ������ ��������������� ������ �������.
		 */
		DOUBLE getError();

		/**
		 * �������� ������ ����� �������.
		 * @return - ������ ����� �������.
		 */
		DOUBLE getFullError();
	};
}

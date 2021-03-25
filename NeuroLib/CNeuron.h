#pragma once

#include "functions.h"
#include "CNeuroWeight.h"

namespace neuro
{
	/** ������ */
	class CNeuron
	{
	public:
		/** ������� ��������� ������� */
		fMathFunc fActivation;

		/** ������� ������������� ������� */
		fMathFunc fCorrercion;

		/** ������ ������� �������� */
		std::list<std::pair<CNeuron*, CNeuroWeight*>> inputNeurons;

		/** ������ �������� �������� */
		std::list<std::pair<CNeuron*, CNeuroWeight*>> outputNeurons;

		/** �������� ������� */
		DOUBLE fValue = 0.f;

		/** ������ ������� */
		DOUBLE fError = 0.f;

		/** ������� ������� �������� */
		BOOL bShift;

		/**
		 * ����������� �������.
		 * @param fCorrercion - ������� ��������� �������.
		 * @param fCorrercion - ������� ������������� �������.
		 * @param bShift - ������� ������� ��������.
		 */
		CNeuron(
			_In_opt_ fMathFunc fActivation = nullptr,
			_In_opt_ fMathFunc fCorrercion = nullptr,
			_In_opt_ BOOL bShift = false)
		{
			this->bShift = bShift;
			this->fActivation = fActivation;
			this->fCorrercion = fCorrercion;
		}

		/**
		 * �������� ��� ����� ����� ���������.
		 * @param neuronWeights - ������ ���� ����� ����� ��������� ����.
		 * @param inputNeuron - ������� ������.
		 * @param outputNeuron - �������� ������.
		 * @return - ��� ����� ����� ���������.
		 */
		static CNeuroWeight& addWeight(
			_Inout_ std::list<CNeuroWeight>& neuronWeights,
			_Inout_ CNeuron& inputNeuron,
			_Inout_ CNeuron& outputNeuron)
		{
			// ������� ��� �����
			neuronWeights.push_back(CNeuroWeight(inputNeuron, outputNeuron));
			auto& weight = neuronWeights.back();

			// ��������� ����� � ������� ������
			inputNeuron.outputNeurons.push_back(std::pair(&outputNeuron, &weight));

			// ��������� ����� � �������� ������
			outputNeuron.inputNeurons.push_back(std::pair(&inputNeuron, &weight));

			return weight;
		}
	};
}

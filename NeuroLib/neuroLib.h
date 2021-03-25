#pragma once

#ifdef __cplusplus
EXTERN_C_START
#endif

/**
* �������� ��������� ����� ��������� ����.
* @param fCorrercion - ������� ��������� ������� ��-���������.
* @param fCorrercion - ������� ������������� ������� ��-���������.
* @param fKf - ����������� �������� ��������� ����.
* @return - ��������� �� ��������� ����. ��� ������ ������ nullptr. 
* GetlastError - ERROR_NOT_ENOUGH_MEMORY
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
neuro::CNeuro* createNeuro(
	_In_ neuro::fMathFuncDelegate fActivation,
	_In_ neuro::fMathFuncDelegate fCorrercion,
	_In_ DOUBLE fKf);

/**
* ������� ��������� ����.
* @param pNeuro - ��������� �� ��������� ����.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
VOID deleteNeuro(
	_Inout_ neuro::CNeuro* pNeuro);

/**
* �������� ���� �������� � ��������� ����.
* @param pNeuro - ��������� �� ��������� ����.
* @param szCountNeuron - ���������� �������� � ����.
* @param bShift - ������� ������� ������� ��������. ���� true �� ��������� ������ ����� �������� ��������.
* @param fCorrercion - ������� ��������� ����� ��� �������� ����.
* @param fCorrercion - ������� ������������� ����� ��� �������� ����.
* @return - ���������� ����� ����. ��� ������ ������ -1.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_NOT_ENOUGH_MEMORY
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
size_t addLayerNeuro(
	_Inout_ neuro::CNeuro* pNeuro,
	_In_ size_t szCountNeuron,
	_In_ BOOL bShift,
	_In_opt_ neuro::fMathFuncDelegate fActivation,
	_In_opt_ neuro::fMathFuncDelegate fCorrercion);

/**
* ������������� ��������� �������� ����� ����� ��� ��������� ����.
* @param pNeuro - ��������� �� ��������� ����.
* @param fMin - ����������� ��������.
* @param fMax - ������������ ��������.
* @return - ����� ��������. ��� ������ ������ false.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
BOOL randomWeightNeuro(
	_Inout_ neuro::CNeuro* pNeuro,
	_In_ DOUBLE fMin,
	_In_ DOUBLE fMax);

/**
* �������� �������� ����� ��������� ����.
* @param pNeuro - ��������� �� ��������� ����.
* @param pInput - ��������� �� ������� ��������.
* @param countInput - ���������� ������� ��������.
* @param pOutput - ��������� �� �������� ��������.
* @param countOutput - ���������� �������� ��������.
* @return - ��������� �������. ��� ������ ������ nullptr.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_NOT_ENOUGH_MEMORY
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
DOUBLE* calcNeuro(
	_Inout_ neuro::CNeuro* pNeuro,
	_In_reads_(countInput) DOUBLE* pInput,
	_In_ size_t countInput,
	_Out_writes_all_(countOutput) DOUBLE* pOutput,
	_In_ size_t countOutput);

/**
* �������� ������ ��������� ����
* @param pNeuro - ��������� �� ��������� ����.
* @param bCorrect - ������� ������������� ����� ����� ����� ����� ��������� ������.
* @param pInput - ��������� �� ������� ��������.
* @param countInput - ���������� ������� ��������.
* @param pOutput - ��������� �� �������� ��������.
* @param countOutput - ���������� �������� ��������.
* @return - ���������� �������� �� ����������. ��� ������ ������ nullptr.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_NOT_ENOUGH_MEMORY
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
DOUBLE* calcErrorNeuro(
	_Inout_ neuro::CNeuro* pNeuro,
	_In_ BOOL bCorrect,
	_In_reads_(countInput) DOUBLE* pInput,
	_In_ size_t countInput,
	_Out_writes_all_(countOutput) DOUBLE* pOutput,
	_In_ size_t countOutput);

/**
* ��������������� ���� ����� ��������� ����, ������ �� ������.
* @param pNeuro - ��������� �� ��������� ����.
* @return - ����� ��������. ��� ������ ������ false.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
BOOL correctWeightNeuro(
	_Inout_ neuro::CNeuro* pNeuro);

/**
* �������� ������ ��������������� ������ ������� ��������� ����.
* @param pNeuro - ��������� �� ��������� ����.
* @return - ������ ��������������� ������ �������. ��� ������ ������ ������������� ��������.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
DOUBLE getErrorNeuro(
	_Inout_ neuro::CNeuro* pNeuro);

/**
* �������� ������ ����� ������� ��������� ����.
* @param pNeuro - ��������� �� ��������� ����.
* @return - ������ ����� �������. ��� ������ ������ ������������� ��������.
* GetlastError - ERROR_INVALID_PARAMETER
* GetlastError - ERROR_INVALID_FUNCTION
*/
NEUROLIB_EXPORT
DOUBLE getFullErrorNeuro(
	_Inout_ neuro::CNeuro* pNeuro);

#ifdef __cplusplus
EXTERN_C_END
#endif

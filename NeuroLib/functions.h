#pragma once

#define NEUROLIB_EXPORT __declspec(dllexport)

namespace neuro
{
#ifdef __cplusplus
	EXTERN_C_START
#endif
	/**
	 * �������� �������������� �������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	typedef std::function<DOUBLE(
		_In_ DOUBLE x)> fMathFunc;

	/**
	 * ������� �������������� �������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	typedef DOUBLE(__stdcall* fMathFuncDelegate)(
		_In_ DOUBLE x);

	/**
	 * ������������� ������� ���������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE Sigmoid(
		_In_ DOUBLE x)
	{
		return 1.0 / (1.0 + exp(-x));
	}

	/**
	 * ������������� ������� ������������� ��������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE SigmoidDx(
		_In_ DOUBLE x)
	{
		return x * (1.0 - x);
	}

	/**
	 * �������� ������� ���������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE Liner_01(
		_In_ DOUBLE x)
	{
		if (x > 1)
			return 1.0 + 0.01 * (x - 1);

		if (x < 0)
			return 0.01 * x;

		return x;
	}

	/**
	 * �������� ������� �������������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE Liner_01Dx(
		_In_ DOUBLE x)
	{
		if (x > 1)
			return 0.01;

		if (x < 0)
			return 0.01;

		return 1;
	}

	/**
	 * �������� �������������  ������� ���������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE Bent_identity(
		_In_ DOUBLE x)
	{
		return (sqrt(x * x + 1.0) - 1.0) / 2.0 + x;
	}

	/**
	 * �������� �������������  ������� �������������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE Bent_identityDx(
		_In_ DOUBLE x)
	{
		return x / (2.0 * sqrt(x * x + 1)) + 1;
	}

	/**
	 * ������������� ������� ���������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE Identical(
		_In_ DOUBLE x)
	{
		return x;
	}

	/**
	 * ������������� ������� �������������.
	 * @param x - ������� �������� ����������� �������.
	 * @return - ��������� ���������� �������.
	 */
	NEUROLIB_EXPORT
	inline DOUBLE IdenticalDx(
		_In_ DOUBLE x)
	{
		return  1.0;
	}

#ifdef __cplusplus
	EXTERN_C_END
#endif
}

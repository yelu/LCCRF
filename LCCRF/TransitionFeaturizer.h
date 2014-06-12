#pragma once

#include <set>
#include "Featurizer.h"
#include "IDAllocator.h"
using std::set;

class TransitionFeaturizer:public Featurizer
{
public:
	TransitionFeaturizer(void);
	virtual ~TransitionFeaturizer(void);
	void Fit(const Document& doc);
	void Transform(const Document& doc, const wstring& s1, const wstring& s2, int j, set<int>& res);
	bool IsHit(const Document& doc, const wstring& s1, const wstring& s2, int j, int featureID);
	const wstring& Name();
	size_t Size();
	void Serialize(const wstring& filePath);
	void Clear();
	wstring FeatureToString(int featureID);

private:

	wstring _MakeTransition(const wstring& s1, const wstring& s2);

	IDAllocator _idAllocator;
	wstring _name;
};


#pragma once

#include <list>
#include "Featurizer.h"
#include <memory>
using std::list;

class FeatureManager
{
public:
	FeatureManager(void);
	virtual ~FeatureManager(void);

	void AddFeaturizer(std::shared_ptr<Featurizer>& featurizer);
	void Fit(const list<Document>& docs);
	void Transform(const Document& doc, const wstring& s1, const wstring& s2, int j, set<int>& res);
	bool IsHit(const Document& doc, const wstring& s1, const wstring& s2, int j, int featureID);
	size_t Size();
	void Clear();
	void Serialize(wstring path);

private:
	list<std::shared_ptr<Featurizer>> _featurizers;
	vector<int> _nextIDs;
};

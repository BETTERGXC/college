void DFS(string& dights,vector<string>& allRet,string curStr,int idx)
{
	if(idx == dights.size()) 
	{
		allRet.push_back(curStr);	
		return;
	}
	string strMap = Map[digits[idx]];
	for(char ch : strMap)
	{
		DFS(dights,allRet,curStr + ch,idx + 1);
	}
}

vector<string> letterCombinations(string dights) 
{
	vector<string> allRet;
	if(dights.empty())
		return allRet;
	DFS(dights,allRet,"",0);
	return allRet;

}
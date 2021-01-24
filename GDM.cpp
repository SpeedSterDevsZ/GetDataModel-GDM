// Copy and paste this somewhere in ur skidded dll 

int GetDatamodel()
{
	int A = 9;
	int B = 3;
	int result = A + B;
	static DWORD DMPad[16]{};
	r_getdatamodel(getdatamodel2(), (DWORD)DMPad);
	DWORD DM = DMPad[0];
	return DM + result;
}

void GetDataModel()
{
	GDM = GetDatamodel();
	ScriptContext = FindFirstClass(GDM, "ScriptContext");
	DWORD oldRL = Adresses::RBX_LuaState(ScriptContext);
	m_RLS = r_lua_newthread(oldRL);
}

// OMG it errors, just find ur thing. you do need a GetDataModel Get Address

Paste in r_lua.h of ur axon


typedef DWORD(__thiscall* gdm2)();
gdm2 getdatamodel2 = (gdm2)(x(0x000F48AA0));

typedef DWORD(__thiscall* getdatamodel)(DWORD, DWORD);
getdatamodel r_getdatamodel = (getdatamodel)(x(0x000F48BF0)); // address for jan 24 2021
 

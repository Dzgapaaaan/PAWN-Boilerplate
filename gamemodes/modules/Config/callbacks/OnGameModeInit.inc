/*!
 * Config/callbacks/OnGameModeInit.inc
 *
 * OnGameModeInit()
 *
 > Priority: 10
 */

{
	this.CB_OnConfigValueChange = GetPublicAddressByName("OnConfigValueChange");
	
	for (new buf[32], idx; (idx = AMX_GetPublicName(idx, buf, !"@Pc_")); ) {
		if (strfind(buf, !".") != -1)
			continue;
		
		CallLocalFunction(buf, "");
	}
	
	this.LoadEntries(true);
}
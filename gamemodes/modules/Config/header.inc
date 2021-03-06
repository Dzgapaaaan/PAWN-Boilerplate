/*!
 * Config/header.inc
 *
 > Priority: 0
 */

// This will cause errors if the macros below fails (i.e. they're not used properly).
stock RegisterConfigVariable;

#define RegisterConfigVariable:%1; \
	forward %1@Pc_(); \
	public %1@Pc_() { \
		Config.RegisterVariableEntry(#%1, tagof((%1)), sizeof((%1)), %1); \
	}

#define RegisterConfigArray:%1; \
	forward %1@Pc_(); \
	public %1@Pc_() { \
		Config.RegisterVariableEntry(#%1, tagof((%1)), sizeof((%1)), %1, true); \
	}

// Forward this since most RegisterConfigVariable will be in headers
this.RegisterVariableEntry(const _key[], tag, size, GLOBAL_TAG_TYPES:...);

enum this.e_CONFIG_ENTRY {
	      KeyHash,
	Alloc:Key,
	      Address,
	      Type,
	      Size
};

enum {
	this.TYPE_INT,
	this.TYPE_FLOAT,
	this.TYPE_ARRAY,
	this.TYPE_STRING
};

stock const
	this.FILE[] = !"config.cfg"
;

new
	this.NumConfigEntries = 0,
	this.ConfigEntries[1024][this.e_CONFIG_ENTRY],
	this.CB_OnConfigValueChange
;
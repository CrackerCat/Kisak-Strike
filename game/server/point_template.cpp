//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Point entity used to create templates out of other entities or groups of entities
//
//=============================================================================//

#include "cbase.h"
#include "entityinput.h"
#include "entityoutput.h"
#include "TemplateEntities.h"
#include "point_template.h"
#include "saverestore_utlvector.h"
#include "mapentities.h"
#include "tier0/icommandline.h"
#include "mapentities_shared.h"
//lwss - hardcode .nut file here instead of generating it. I don't think it will change as of right now.
//Generated with: `perl texttoarray.pl ../../game/server/spawn_helper.nut g_Script_spawn_helper > /tmp/file.h`
//#include "spawn_helper_nut.h"
static const unsigned char g_Script_spawn_helper[] = {
        0x2f,0x2f,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,
        0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,
        0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x0a,
        0x2f,0x2f,0x20,0x41,0x6e,0x20,0x73,0x70,0x61,0x77,0x6e,0x65,0x72,0x20,0x6f,0x6e,0x20,0x74,0x68,0x65,
        0x20,0x73,0x65,0x72,0x76,0x65,0x72,0x20,0x69,0x73,0x20,0x67,0x65,0x74,0x74,0x69,0x6e,0x67,0x20,0x72,
        0x65,0x61,0x64,0x79,0x20,0x74,0x6f,0x0a,0x2f,0x2f,0x20,0x70,0x72,0x65,0x73,0x70,0x61,0x77,0x6e,0x20,
        0x61,0x6e,0x20,0x65,0x6e,0x74,0x69,0x74,0x79,0x2e,0x20,0x49,0x74,0x20,0x63,0x61,0x6c,0x6c,0x73,0x20,
        0x74,0x68,0x69,0x73,0x20,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x73,0x65,0x6e,0x64,0x69,
        0x6e,0x67,0x20,0x75,0x73,0x0a,0x2f,0x2f,0x20,0x74,0x68,0x65,0x20,0x65,0x6e,0x74,0x69,0x74,0x79,0x20,
        0x74,0x68,0x61,0x74,0x20,0x69,0x74,0x27,0x73,0x20,0x70,0x72,0x65,0x70,0x61,0x72,0x69,0x6e,0x67,0x20,
        0x74,0x6f,0x20,0x73,0x70,0x61,0x77,0x6e,0x2e,0x20,0x0a,0x2f,0x2f,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,
        0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,
        0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,
        0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x3d,0x0a,0x0a,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,
        0x20,0x5f,0x5f,0x45,0x78,0x65,0x63,0x75,0x74,0x65,0x50,0x72,0x65,0x53,0x70,0x61,0x77,0x6e,0x28,0x20,
        0x65,0x6e,0x74,0x69,0x74,0x79,0x20,0x29,0x20,0x0a,0x7b,0x0a,0x09,0x5f,0x5f,0x45,0x6e,0x74,0x69,0x74,
        0x79,0x4d,0x61,0x6b,0x65,0x72,0x52,0x65,0x73,0x75,0x6c,0x74,0x20,0x3c,0x2d,0x20,0x7b,0x7d,0x0a,0x09,
        0x69,0x66,0x20,0x28,0x20,0x22,0x50,0x72,0x65,0x53,0x70,0x61,0x77,0x6e,0x49,0x6e,0x73,0x74,0x61,0x6e,
        0x63,0x65,0x22,0x20,0x69,0x6e,0x20,0x74,0x68,0x69,0x73,0x20,0x29,0x0a,0x09,0x7b,0x0a,0x09,0x09,0x6c,
        0x6f,0x63,0x61,0x6c,0x20,0x6f,0x76,0x65,0x72,0x72,0x69,0x64,0x65,0x73,0x20,0x3d,0x20,0x50,0x72,0x65,
        0x53,0x70,0x61,0x77,0x6e,0x49,0x6e,0x73,0x74,0x61,0x6e,0x63,0x65,0x28,0x20,0x65,0x6e,0x74,0x69,0x74,
        0x79,0x2e,0x47,0x65,0x74,0x43,0x6c,0x61,0x73,0x73,0x6e,0x61,0x6d,0x65,0x28,0x29,0x2c,0x20,0x65,0x6e,
        0x74,0x69,0x74,0x79,0x2e,0x47,0x65,0x74,0x4e,0x61,0x6d,0x65,0x28,0x29,0x20,0x29,0x3b,0x0a,0x09,0x09,
        0x6c,0x6f,0x63,0x61,0x6c,0x20,0x74,0x79,0x70,0x65,0x20,0x3d,0x20,0x74,0x79,0x70,0x65,0x6f,0x66,0x28,
        0x20,0x6f,0x76,0x65,0x72,0x72,0x69,0x64,0x65,0x73,0x20,0x29,0x3b,0x0a,0x09,0x09,0x69,0x66,0x20,0x28,
        0x20,0x74,0x79,0x70,0x65,0x20,0x3d,0x3d,0x20,0x22,0x74,0x61,0x62,0x6c,0x65,0x22,0x20,0x29,0x0a,0x09,
        0x09,0x7b,0x0a,0x09,0x09,0x09,0x66,0x6f,0x72,0x65,0x61,0x63,0x68,0x28,0x20,0x6b,0x65,0x79,0x2c,0x20,
        0x76,0x61,0x6c,0x75,0x65,0x20,0x69,0x6e,0x20,0x6f,0x76,0x65,0x72,0x72,0x69,0x64,0x65,0x73,0x20,0x29,
        0x0a,0x09,0x09,0x09,0x7b,0x0a,0x09,0x09,0x09,0x09,0x73,0x77,0x69,0x74,0x63,0x68,0x20,0x28,0x20,0x74,
        0x79,0x70,0x65,0x6f,0x66,0x28,0x20,0x76,0x61,0x6c,0x75,0x65,0x20,0x29,0x20,0x29,0x0a,0x09,0x09,0x09,
        0x09,0x7b,0x0a,0x09,0x09,0x09,0x09,0x63,0x61,0x73,0x65,0x20,0x22,0x73,0x74,0x72,0x69,0x6e,0x67,0x22,
        0x3a,0x0a,0x09,0x09,0x09,0x09,0x09,0x7b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x65,0x6e,0x74,0x69,0x74,
        0x79,0x2e,0x5f,0x5f,0x4b,0x65,0x79,0x56,0x61,0x6c,0x75,0x65,0x46,0x72,0x6f,0x6d,0x53,0x74,0x72,0x69,
        0x6e,0x67,0x28,0x20,0x6b,0x65,0x79,0x2c,0x20,0x76,0x61,0x6c,0x75,0x65,0x20,0x29,0x3b,0x0a,0x09,0x09,
        0x09,0x09,0x09,0x09,0x62,0x72,0x65,0x61,0x6b,0x3b,0x0a,0x09,0x09,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,
        0x09,0x09,0x63,0x61,0x73,0x65,0x20,0x22,0x69,0x6e,0x74,0x65,0x67,0x65,0x72,0x22,0x3a,0x0a,0x09,0x09,
        0x09,0x09,0x09,0x7b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x65,0x6e,0x74,0x69,0x74,0x79,0x2e,0x5f,0x5f,
        0x4b,0x65,0x79,0x56,0x61,0x6c,0x75,0x65,0x46,0x72,0x6f,0x6d,0x49,0x6e,0x74,0x28,0x20,0x6b,0x65,0x79,
        0x2c,0x20,0x76,0x61,0x6c,0x75,0x65,0x20,0x29,0x3b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x62,0x72,0x65,
        0x61,0x6b,0x3b,0x0a,0x09,0x09,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,0x09,0x09,0x63,0x61,0x73,0x65,0x20,
        0x22,0x66,0x6c,0x6f,0x61,0x74,0x22,0x3a,0x0a,0x09,0x09,0x09,0x09,0x63,0x61,0x73,0x65,0x20,0x22,0x62,
        0x6f,0x6f,0x6c,0x22,0x3a,0x0a,0x09,0x09,0x09,0x09,0x09,0x7b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x65,
        0x6e,0x74,0x69,0x74,0x79,0x2e,0x5f,0x5f,0x4b,0x65,0x79,0x56,0x61,0x6c,0x75,0x65,0x46,0x72,0x6f,0x6d,
        0x46,0x6c,0x6f,0x61,0x74,0x28,0x20,0x6b,0x65,0x79,0x2c,0x20,0x76,0x61,0x6c,0x75,0x65,0x2e,0x74,0x6f,
        0x66,0x6c,0x6f,0x61,0x74,0x28,0x29,0x20,0x29,0x3b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x62,0x72,0x65,
        0x61,0x6b,0x3b,0x0a,0x09,0x09,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,0x09,0x09,0x09,0x0a,0x09,0x09,0x09,
        0x09,0x63,0x61,0x73,0x65,0x20,0x22,0x56,0x65,0x63,0x74,0x6f,0x72,0x22,0x3a,0x0a,0x09,0x09,0x09,0x09,
        0x09,0x7b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x65,0x6e,0x74,0x69,0x74,0x79,0x2e,0x5f,0x5f,0x4b,0x65,
        0x79,0x56,0x61,0x6c,0x75,0x65,0x46,0x72,0x6f,0x6d,0x56,0x65,0x63,0x74,0x6f,0x72,0x28,0x20,0x6b,0x65,
        0x79,0x2c,0x20,0x76,0x61,0x6c,0x75,0x65,0x20,0x29,0x3b,0x0a,0x09,0x09,0x09,0x09,0x09,0x09,0x62,0x72,
        0x65,0x61,0x6b,0x0a,0x09,0x09,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,0x09,0x09,0x09,0x0a,0x09,0x09,0x09,
        0x09,0x64,0x65,0x66,0x61,0x75,0x6c,0x74,0x3a,0x0a,0x09,0x09,0x09,0x09,0x09,0x7b,0x0a,0x09,0x09,0x09,
        0x09,0x09,0x09,0x70,0x72,0x69,0x6e,0x74,0x6c,0x28,0x20,0x22,0x43,0x61,0x6e,0x6e,0x6f,0x74,0x20,0x75,
        0x73,0x65,0x20,0x22,0x20,0x2b,0x20,0x74,0x79,0x70,0x65,0x6f,0x66,0x28,0x20,0x76,0x61,0x6c,0x75,0x65,
        0x20,0x29,0x20,0x2b,0x20,0x22,0x20,0x61,0x73,0x20,0x61,0x20,0x6b,0x65,0x79,0x22,0x20,0x29,0x3b,0x0a,
        0x09,0x09,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,0x09,0x7d,0x0a,0x09,0x09,
        0x7d,0x0a,0x09,0x09,0x0a,0x09,0x09,0x69,0x66,0x20,0x28,0x20,0x74,0x79,0x70,0x65,0x20,0x3d,0x3d,0x20,
        0x22,0x62,0x6f,0x6f,0x6c,0x22,0x20,0x29,0x0a,0x09,0x09,0x7b,0x0a,0x09,0x09,0x09,0x72,0x65,0x74,0x75,
        0x72,0x6e,0x20,0x6f,0x76,0x65,0x72,0x72,0x69,0x64,0x65,0x73,0x3b,0x0a,0x09,0x09,0x7d,0x0a,0x09,0x7d,
        0x0a,0x7d,0x3b,0x0a,0x0a,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x5f,0x5f,0x46,0x69,0x6e,0x69,
        0x73,0x68,0x53,0x70,0x61,0x77,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x09,0x5f,0x5f,0x45,0x6e,0x74,0x69,0x74,
        0x79,0x4d,0x61,0x6b,0x65,0x72,0x52,0x65,0x73,0x75,0x6c,0x74,0x20,0x3c,0x2d,0x20,0x6e,0x75,0x6c,0x6c,
        0x3b,0x0a,0x7d,0x0a,0x00
};
/**
//=========================================================
// An spawner on the server is getting ready to
// prespawn an entity. It calls this function, sending us
// the entity that it's preparing to spawn.
//=========================================================

function __ExecutePreSpawn( entity )
{
	__EntityMakerResult <- {}
	if ( "PreSpawnInstance" in this )
	{
		local overrides = PreSpawnInstance( entity.GetClassname(), entity.GetName() );
		local type = typeof( overrides );
		if ( type == "table" )
		{
			foreach( key, value in overrides )
			{
				switch ( typeof( value ) )
				{
				case "string":
					{
						entity.__KeyValueFromString( key, value );
						break;
					}
				case "integer":
					{
						entity.__KeyValueFromInt( key, value );
						break;
					}
				case "float":
				case "bool":
					{
						entity.__KeyValueFromFloat( key, value.tofloat() );
						break;
					}

				case "Vector":
					{
						entity.__KeyValueFromVector( key, value );
						break
					}

				default:
					{
						printl( "Cannot use " + typeof( value ) + " as a key" );
					}
				}
			}
		}

		if ( type == "bool" )
		{
			return overrides;
		}
	}
};

function __FinishSpawn()
{
	__EntityMakerResult <- null;
}
*/
//lwss end

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#define SF_POINTTEMPLATE_DONTREMOVETEMPLATEENTITIES		0x0001

// Level designers can suppress the uniquification of the spawned entity
// names with a spawnflag, provided they guarantee that only one instance
// of the entities will ever be spawned at a time.
#define	SF_POINTTEMPLATE_PRESERVE_NAMES					0x0002


LINK_ENTITY_TO_CLASS(point_template, CPointTemplate);

BEGIN_SIMPLE_DATADESC( template_t )
	DEFINE_FIELD( iTemplateIndex,	FIELD_INTEGER ),
	DEFINE_FIELD( matEntityToTemplate, FIELD_VMATRIX ),
END_DATADESC()

BEGIN_DATADESC( CPointTemplate )
	// Keys

	// Silence, Classcheck!
	// DEFINE_ARRAY( m_iszTemplateEntityNames, FIELD_STRING, MAX_NUM_TEMPLATES ),

	DEFINE_KEYFIELD( m_iszTemplateEntityNames[0], FIELD_STRING, "Template01"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[1], FIELD_STRING, "Template02"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[2], FIELD_STRING, "Template03"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[3], FIELD_STRING, "Template04"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[4], FIELD_STRING, "Template05"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[5], FIELD_STRING, "Template06"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[6], FIELD_STRING, "Template07"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[7], FIELD_STRING, "Template08"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[8], FIELD_STRING, "Template09"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[9], FIELD_STRING, "Template10"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[10], FIELD_STRING, "Template11"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[11], FIELD_STRING, "Template12"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[12], FIELD_STRING, "Template13"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[13], FIELD_STRING, "Template14"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[14], FIELD_STRING, "Template15"),
	DEFINE_KEYFIELD( m_iszTemplateEntityNames[15], FIELD_STRING, "Template16"),
	DEFINE_UTLVECTOR( m_hTemplateEntities, FIELD_CLASSPTR ),

	DEFINE_UTLVECTOR( m_hTemplates, FIELD_EMBEDDED ),

	// Inputs
	DEFINE_INPUTFUNC( FIELD_VOID, "ForceSpawn", InputForceSpawn ),

	// Outputs
	DEFINE_OUTPUT( m_pOutputOnSpawned, "OnEntitySpawned" ),

END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose: A simple system to help precache point_template entities ... ywb
//-----------------------------------------------------------------------------
class CPointTemplatePrecacher : public CAutoGameSystem
{
public:

	CPointTemplatePrecacher( char const *name ) : CAutoGameSystem( name )
	{
	}

	void AddToPrecache( CPointTemplate *ent )
	{
		m_Ents.AddToTail( ent );
	}

	virtual void LevelInitPreEntity()
	{
		m_Ents.RemoveAll();
	}

	virtual void Shutdown()
	{
		m_Ents.RemoveAll();
	}

	void Precache()
	{
		int c = m_Ents.Count();
		for ( int i = 0 ; i < c; ++i )
		{
			CPointTemplate *ent = m_Ents[ i ].Get();
			if ( ent )
			{
				ent->PerformPrecache();
			}
		}

		m_Ents.RemoveAll();
	}
private:

	CUtlVector< CHandle< CPointTemplate > >	m_Ents;
};

CPointTemplatePrecacher g_PointTemplatePrecacher( "CPointTemplatePrecacher" );

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void PrecachePointTemplates()
{
	g_PointTemplatePrecacher.Precache();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPointTemplate::Spawn( void )
{
	Precache();
	ScriptInstallPreSpawnHook();
}

void CPointTemplate::Precache()
{
	// We can't call precache right when we instance the template, we need to defer it until after all map entities have 
	//  been loaded, so add this template to a list which is cleared after map entity parsing is completed.
	g_PointTemplatePrecacher.AddToPrecache( this );
}

//-----------------------------------------------------------------------------
// Purpose: Level designers can suppress the uniquification of the spawned entity
//			names with a spawnflag, provided they guarantee that only one instance
//			of the entities will ever be spawned at a time.
//-----------------------------------------------------------------------------
bool CPointTemplate::AllowNameFixup()
{
	return !HasSpawnFlags( SF_POINTTEMPLATE_PRESERVE_NAMES );
}

//-----------------------------------------------------------------------------
// Purpose: Called at the start of template initialization for this point_template.
//			Find all the entities referenced by this point_template, which will 
//			then be turned into templates by the map-parsing code.
//-----------------------------------------------------------------------------
void CPointTemplate::StartBuildingTemplates( void )
{
	// Build our list of template entities
	for ( int i = 0; i < MAX_NUM_TEMPLATES; i++ )
	{
		if ( m_iszTemplateEntityNames[i] != NULL_STRING )
		{
			CBaseEntity	*pEntity = NULL;
			int iOldNum = m_hTemplateEntities.Count();
			// Add all the entities with the matching targetname
			while ( (pEntity = gEntList.FindEntityByName( pEntity, STRING(m_iszTemplateEntityNames[i]) )) != NULL )
			{
				m_hTemplateEntities.AddToTail( pEntity );
			}

			// Useful mapmaker warning
			if ( iOldNum == m_hTemplateEntities.Count() )
			{
				Warning( "Couldn't find any entities named %s, which point_template %s is specifying.\n", STRING(m_iszTemplateEntityNames[i]), STRING(GetEntityName()) );
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Purpose: Called at the end of template initialization for this point_template.
//			All of our referenced entities have now been destroyed.
//-----------------------------------------------------------------------------
void CPointTemplate::FinishBuildingTemplates( void )
{
	// Our template entities are now gone, deleted by the server post turning them into templates.
	m_hTemplateEntities.Purge();

	// Now tell the template system to hook up all the Entity I/O connections within our set of templates.
	Templates_ReconnectIOForGroup( this );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPointTemplate::AddTemplate( CBaseEntity *pEntity, const char *pszMapData, int nLen )
{
	// Add it to the template list
	int iIndex = Templates_Add( pEntity, pszMapData, nLen );
	if ( iIndex == -1 )
	{
		Warning( "point_template %s failed to add template.\n", STRING(GetEntityName()) );
		return;
	}

	template_t newTemplate;
	newTemplate.iTemplateIndex = iIndex;

	// Store the entity's origin & angles in a matrix in the template's local space
	VMatrix matTemplateToWorld, matWorldToTemplate, matEntityToWorld, matEntityToTemplate;
	matTemplateToWorld.SetupMatrixOrgAngles( GetAbsOrigin(), GetAbsAngles() );
	matTemplateToWorld.InverseTR( matWorldToTemplate );
	matEntityToWorld.SetupMatrixOrgAngles( pEntity->GetAbsOrigin(), pEntity->GetAbsAngles() );
	MatrixMultiply( matWorldToTemplate, matEntityToWorld, matEntityToTemplate );

	newTemplate.matEntityToTemplate = matEntityToTemplate;
	m_hTemplates.AddToTail( newTemplate );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
bool CPointTemplate::ShouldRemoveTemplateEntities( void )
{
	return ( !(m_spawnflags & SF_POINTTEMPLATE_DONTREMOVETEMPLATEENTITIES) );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int	CPointTemplate::GetNumTemplates( void )
{
	return m_hTemplates.Count();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int	CPointTemplate::GetTemplateIndexForTemplate( int iTemplate )
{
	Assert( iTemplate < m_hTemplates.Count() );
	return m_hTemplates[iTemplate].iTemplateIndex;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int CPointTemplate::GetNumTemplateEntities( void )
{
	return m_hTemplateEntities.Count();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
CBaseEntity	*CPointTemplate::GetTemplateEntity( int iTemplateNumber )
{
	Assert( iTemplateNumber < m_hTemplateEntities.Count() );

	return m_hTemplateEntities[iTemplateNumber];
}


//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPointTemplate::PerformPrecache()
{
	// Go through all our templated map data and precache all the entities in it
	int iTemplates = m_hTemplates.Count();
	if ( !iTemplates )
	{
		Msg("Precache called on a point_template that has no templates: %s\n", STRING(GetEntityName()) );
		return;
	}

	// Tell the template system we're about to start a new template
	Templates_StartUniqueInstance();

	//HierarchicalSpawn_t *pSpawnList = (HierarchicalSpawn_t*)stackalloc( iTemplates * sizeof(HierarchicalSpawn_t) );

	int i;
	for ( i = 0; i < iTemplates; i++ )
	{
		//CBaseEntity *pEntity = NULL;
		char *pMapData;
		int iTemplateIndex = m_hTemplates[i].iTemplateIndex;

		// Some templates have Entity I/O connecting the entities within the template.
		// Unique versions of these templates need to be created whenever they're instanced.
		int nStringSize;
		if ( AllowNameFixup() && Templates_IndexRequiresEntityIOFixup( iTemplateIndex ) )
		{
			// This template requires instancing. 
			// Create a new mapdata block and ask the template system to fill it in with
			// a unique version (with fixed Entity I/O connections).
			pMapData = Templates_GetEntityIOFixedMapData( iTemplateIndex );
			
		}
		else
		{
			// Use the unmodified mapdata
			pMapData = (char*)STRING( Templates_FindByIndex( iTemplateIndex ) );
		}

		nStringSize = Templates_GetStringSize( iTemplateIndex );

		// Create the entity from the mapdata
		MapEntity_PrecacheEntity( pMapData, nStringSize );
	}
}

//-----------------------------------------------------------------------------
// Purpose: Spawn the entities I contain
// Input  : &vecOrigin - 
//			&vecAngles - 
//			pEntities - 
//			pEntityMaker - The Entity Maker entity that invoked this call.
// Output : Returns true on success, false on failure.
//-----------------------------------------------------------------------------
bool CPointTemplate::CreateInstance( const Vector &vecOrigin, const QAngle &vecAngles, CUtlVector<CBaseEntity*> *pEntities, CBaseEntity *pEntityMaker, bool bCreateTime )
{
	// Go through all our templated map data and spawn all the entities in it
	int iTemplates = m_hTemplates.Count();
	if ( !iTemplates )
	{
		Msg("CreateInstance called on a point_template that has no templates: %s\n", STRING(GetEntityName()) );
		return false;
	}

	// Tell the template system we're about to start a new template
	Templates_StartUniqueInstance();

	HierarchicalSpawn_t *pSpawnList = (HierarchicalSpawn_t*)stackalloc( iTemplates * sizeof(HierarchicalSpawn_t) );

	int i;
	for ( i = 0; i < iTemplates; i++ )
	{
		CBaseEntity *pEntity = NULL;
		char *pMapData;
		int iTemplateIndex = m_hTemplates[i].iTemplateIndex;

		// Some templates have Entity I/O connecting the entities within the template.
		// Unique versions of these templates need to be created whenever they're instanced.
		if ( AllowNameFixup() && ( Templates_IndexRequiresEntityIOFixup( iTemplateIndex ) || m_ScriptScope.IsInitialized() ) )
		{
			// This template requires instancing. 
			// Create a new mapdata block and ask the template system to fill it in with
			// a unique version (with fixed Entity I/O connections).
			pMapData = Templates_GetEntityIOFixedMapData( iTemplateIndex );
		}
		else
		{
			// Use the unmodified mapdata
			pMapData = (char*)STRING( Templates_FindByIndex( iTemplateIndex ) );
		}

		// Create the entity from the mapdata
		MapEntity_ParseEntity( pEntity, pMapData, NULL );
		if ( pEntity == NULL )
		{
			Msg("Failed to initialize templated entity with mapdata: %s\n", pMapData );
			return false;
		}

		// Get a matrix that'll convert from world to the new local space
		VMatrix matNewTemplateToWorld, matStoredLocalToWorld;
		matNewTemplateToWorld.SetupMatrixOrgAngles( vecOrigin, vecAngles );
		MatrixMultiply( matNewTemplateToWorld, m_hTemplates[i].matEntityToTemplate, matStoredLocalToWorld );

		// Get the world origin & angles from the stored local coordinates
		Vector vecNewOrigin;
		QAngle vecNewAngles;
		vecNewOrigin = matStoredLocalToWorld.GetTranslation();
		MatrixToAngles( matStoredLocalToWorld, vecNewAngles );

		// Set its origin & angles
		pEntity->SetAbsOrigin( vecNewOrigin );
		pEntity->SetAbsAngles( vecNewAngles );

		if( AllowNameFixup() )
		{
			pEntity->MarkNeedsNamePurge();
		}

		if ( ScriptPreInstanceSpawn( &m_ScriptScope, pEntity, Templates_FindByIndex( iTemplateIndex ) ) )
		{
			pSpawnList[i].m_pEntity = pEntity;
		}
		else
		{
			pSpawnList[i].m_pEntity = NULL;
			UTIL_RemoveImmediate( pEntity );
		}
		pSpawnList[i].m_nDepth = 0;
		pSpawnList[i].m_pDeferredParent = NULL;
	}

	SpawnHierarchicalList( iTemplates, pSpawnList, true );

	// Set the time of creation for these entities.
	if ( bCreateTime )
	{
#if defined(ENABLE_CREATE_TIME)
		float flCreateTime = gpGlobals->curtime;
		for ( i = 0; i < iTemplates; ++i )
		{
			if ( pSpawnList[i].m_pEntity )
			{
				pSpawnList[i].m_pEntity->SetCreateTime( flCreateTime );
			}
		}
#endif
	}

	for ( i = 0; i < iTemplates; ++i )
	{
		if ( pSpawnList[i].m_pEntity )
		{
			pEntities->AddToTail( pSpawnList[i].m_pEntity );
		}
	}

	return true;
}


//-----------------------------------------------------------------------------
// 
//-----------------------------------------------------------------------------
void CPointTemplate::CreationComplete( const CUtlVector<CBaseEntity*> &entities )
{
	if ( !entities.Count() )
		return;

	ScriptPostSpawn( &m_ScriptScope, (CBaseEntity **)entities.Base(), entities.Count() );
}

//-----------------------------------------------------------------------------
// Purpose: 
// Input  : &inputdata - 
//-----------------------------------------------------------------------------
void CPointTemplate::InputForceSpawn( inputdata_t &inputdata )
{
	// Spawn our template
	CUtlVector<CBaseEntity*> hNewEntities;
	if ( !CreateInstance( GetAbsOrigin(), GetAbsAngles(), &hNewEntities ) )
		return;
	
	CreationComplete( hNewEntities );

	// Fire our output
	m_pOutputOnSpawned.FireOutput( this, this );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ScriptInstallPreSpawnHook()
{
	if ( g_pScriptVM && !g_pScriptVM->ValueExists( "__ExecutePreSpawn" ) )
	{
		g_pScriptVM->Run( g_Script_spawn_helper );
	}
}

//-----------------------------------------------------------------------------
// Purpose:	This function is called after a spawner creates its child entity
//			but before the keyvalues are injected. This gives us an 
//			opportunity to change any keyvalues before the entity is 
//			configured and spawned. In this case, we see if there is a VScript
//			that wants to change anything about this entity. 
//-----------------------------------------------------------------------------
bool ScriptPreInstanceSpawn( CScriptScope *pScriptScope, CBaseEntity *pChild, string_t iszKeyValueData )
{
	if ( !pScriptScope->IsInitialized() )
	{
		return true;
	}

	if ( !pScriptScope->ValueExists( "PreSpawnInstance" ) )
	{
		return true;
	}

	ScriptVariant_t result;
	if ( pScriptScope->Call( "__ExecutePreSpawn", &result, ToHScript( pChild ) ) != SCRIPT_DONE )
		return true;

	if ( ( result.m_type == FIELD_BOOLEAN && !result.m_bool ) || ( result.m_type == FIELD_INTEGER && !result.m_int ) )
		return false;

	return true;

}

void ScriptPostSpawn( CScriptScope *pScriptScope, CBaseEntity **ppEntities, int nEntities )
{
	if ( !pScriptScope->IsInitialized() )
		return;

	HSCRIPT hPostSpawnFunc = pScriptScope->LookupFunction( "PostSpawn" );

	if ( !hPostSpawnFunc )
		return;

	ScriptVariant_t varEntityMakerResultTable;
	if ( g_pScriptVM->GetValue( *pScriptScope, "__EntityMakerResult", &varEntityMakerResultTable ) )
	{
		if ( varEntityMakerResultTable.m_type == FIELD_HSCRIPT )
		{
			HSCRIPT hEntityMakerResultTable = varEntityMakerResultTable.m_hScript;
			char szEntName[256];
			for ( int i = 0; i < nEntities; i++ )
			{
				V_strncpy( szEntName, ppEntities[i]->GetEntityNameAsCStr(), ARRAYSIZE(szEntName) );
				char *pAmpersand = V_strrchr( szEntName, '&' );
				if ( pAmpersand )
					*pAmpersand = 0;
				g_pScriptVM->SetValue( hEntityMakerResultTable, szEntName, ToHScript( ppEntities[i] ) );
			}
			pScriptScope->Call( hPostSpawnFunc, NULL, hEntityMakerResultTable );
			pScriptScope->Call( "__FinishSpawn" );
		}
		g_pScriptVM->ReleaseValue( varEntityMakerResultTable );
	}
	g_pScriptVM->ReleaseFunction( hPostSpawnFunc );
}
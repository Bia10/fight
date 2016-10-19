
//**********************************************************
// ����༭��
//**********************************************************

// UserData.h: interface for the CUserData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERDATA_H__6C3EB549_7325_4A50_82DF_FD07A49E1300__INCLUDED_)
#define AFX_USERDATA_H__6C3EB549_7325_4A50_82DF_FD07A49E1300__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786)
#include "define.h"
#include "GameObj.h"
#include "windows.h"
#include "GameData.h"

const int		MEDAL_BUFSIZE		= 64 + 1;
const int		TITLE_BUFSIZE		= 64 + 1;

//////////////////////////////////////////////////////////////////////
enum USERDATA
{
    USERDATA_NAME = 1,
};

char	szUserTable[];


//////////////////////////////////////////////////////////////////////
//�Ƿ��Զ��������
enum {_NOT_AUTOALLOT = 0, _AUTOALLOT = 1};

struct WantedInfoStruct
{
    char	szName[_MAX_NAMESIZE];
    int		nBonuty;
    OBJID	idModifyWanted;
    OBJID	idWanted;
};

struct	UserInfoStruct
{
    OBJID			id;

    NAMESTR			szName;			// ����
    NAMESTR			szMate;			// ��ż����

    DWORD			dwLookface;		//int(4) unsigned
    DWORD			dwHair;
    char			cLength;		// �߶� -- zlong 2004-02-03
    char			cFat;			// ���� -- zlong 2004-02-03
    DWORD			dwMoney;			//int(4) unsigned	���ϵĽ�Ǯ
    DWORD			dwMoney_saved;	//int(4) unsigned		�洢�Ľ�Ǯ
    DWORD			dwCoin_money;	//mediumint(3) unsigned
    UCHAR			ucLevel;			//tinyint(1) unsigned	�ȼ�
    int				nExp;			//int(4) ?? Ϊʲô����unsigned?	��ǰ����
    USHORT			usForce;		//smallint(2) unsigned			����
    USHORT			usConstitution;	//smallint(2) unsigned			���� -- add by zlong 2004-1-30
    USHORT			usDexterity;	//smallint(2) unsigned			����
    USHORT			usHealth;		//smallint(2) unsigned			����
    USHORT			usSoul;			//smallint(2) unsigned			����
    USHORT			usSpeed;		//smallint(2) unsigned			�ٶ� -- �����ݲ��ҹ�
    USHORT			usAdditional_point; //smallint(2) unsigned		�ɷ������
    UCHAR			ucAuto_allot;		//tinyint(1) unsigned		�Ƿ��Զ�����
    USHORT			usLife;
    USHORT			usMana;			//smallint(2) unsigned
    UCHAR			ucProfession;	//tinyint(2) unsigned			ְҵ
    int				nPotential;		//int(4)						Ǳ��
    SHORT			sPk;			//smallint(2)
    UCHAR			ucNobility;		//tinyint(1) unsigned
    char			setMedal[MEDAL_BUFSIZE];			//int(4) unsigned	ѫ��
    DWORD			dwMedal_select;	//int(4) unsigned
    char			setTitle[TITLE_BUFSIZE];			//int(4) unsigned	�ƺ�
    DWORD			dwTitle_select;	//int(4) unsigned
    UCHAR			ucMetempsychosis;	//tinyint(1) unsigned		ת���ֻ�
    OBJID			idSyndicate;	//int(4) unsigned				��������
    OBJID			idRecordmap;	//int(4)
    USHORT			usRecordX;
    USHORT			usRecordY;		//int(4) unsigned
    OBJID			idAccount;	//int(4) unsigned
    DWORD			dwLast_login;	 //int(8) unsigned
    DWORD			dwTaskMask;
    //	DWORD			dwVirtue;
    OBJID			idHome;	//int(4) unsigned
    DWORD			dwLockKey;
    int				nTutorExp;
    UCHAR			ucTutorLevel;
    DWORD			dwMaxlifePercent;	// ��ǰ���Ѫ��ǧ�ֱ�

    UCHAR			ucMercenaryRank;	// Ӷ���ȼ�
    DWORD			dwMercenaryExp;		// Ӷ������

    UCHAR			ucNobilityRank;		// ��λ
    DWORD			dwExploit;			// ��ѫֵ

    // �����ʱ״̬
    I64				i64Effect;
    DWORD			dwStatus;
    UCHAR			ucPkMode;			// PKģʽ
    USHORT			usEnergy;			// ��ǰ����
    USHORT			usMaxEnergy;		// �������
    DWORD			dwCurrLockKey;

    DWORD			dwMonsterType;		//? only use for just change mapgroup
    DWORD			dwMonsterSecs;		//? only use for just change mapgroup

    // wanted
    struct WantedInfoStruct infoWanted;
    OBJID	idPoliceWanted;
};


class IRecord;
class IDatabase;
class CUserData
{
public:
    CUserData();
    virtual ~CUserData();

#ifdef _DEBUG
    void			SetName			(const char* pszName);
#endif

protected:
    bool	Create					(OBJID idUser, IDatabase* pDb);
    bool	LoadInfo				(void);
    bool	SaveInfo				(void);

public: // set to info, use by CUser
    DWORD GetLastLogin();
    void			SetMate			(LPCTSTR szMate, BOOL bUpdate = TRUE);	// ����ʹ�ã�Ĭ��ֱ���޸����ݿ�
    char*			GetMate			();

    void			SetLife			(int nLife, BOOL bUpdate = false);
    USHORT			GetLife			()	{return m_Info.usLife;}

    int				GetMana			()	{return m_Info.usMana;}
    void			SetMana			(int nPower, BOOL bUpdate = false);

    void			SetExp			(int nExp, BOOL bUpdate = false);
    int				GetExp			()	{return m_Info.nExp;}

    void			SetPk			(int nPk, BOOL bUpdate = TRUE);	// ����ʹ�ã�Ĭ��ֱ���޸����ݿ�
    int				GetPk			()	{return m_Info.sPk;}

    void			SetLev			(int nLev, BOOL bUpdate = TRUE);
    int				GetLev			();

    void			SetForce		(int nForce, BOOL bUpdate = TRUE);
    DWORD			GetForce		()  {return m_Info.usForce;}

    void			SetConstitution	(int nConstitution, BOOL bUpdate = TRUE);
    DWORD			GetConstitution	()	{ return m_Info.usConstitution; }

    void			SetAddPoint		(int nAddPoint, BOOL bUpdate = TRUE);
    int				GetAddPoint		();

    void			SetPotential	(int nData, BOOL fUpdate = TRUE);	// ����Ǳ��ֵ
    void			SetMedalSelect	(int nData, BOOL fUpdate = TRUE);
    void			SetTitleSelect	(int nData, BOOL fUpdate = TRUE);

    void			SetAutoAllot	(int nAutoAllot, BOOL fUpdate = TRUE);
    int				GetAutoAllot	();

    void			SetMetempsychosis	(int nMetempsychosis, BOOL fUpdate = TRUE);
    int				GetMetempsychosis	();

    void			SetMoney		(int nMoney, BOOL bUpdate = false);	// �ܳ�ʹ�ã�Ĭ�ϲ�ֱ���޸����ݿ�
    void			SetMoneySaved	(int nMoney, BOOL bUpdate = false);	// �ܳ�ʹ�ã�Ĭ�ϲ�ֱ���޸����ݿ�

    void			SetRecordPos	(OBJID idMap, DWORD dwX, DWORD dwY, BOOL bUpdate = false);
    OBJID			GetRecordMap	()	{return m_Info.idRecordmap;}
    DWORD			GetRecordX		()	{return m_Info.usRecordX;}
    DWORD			GetRecordY		()	{return m_Info.usRecordY;}

    void			SetProfession	(DWORD dwProfession, BOOL bUpdate = TRUE);	// ����ʹ�ã�Ĭ��ֱ���޸����ݿ�
    DWORD			GetProfession	()	{return m_Info.ucProfession;}

    void			SetDexterity	(DWORD dwDex, BOOL bUpdate = TRUE);
    DWORD			GetDexterity	()	{return m_Info.usDexterity;}

    void			SetSpeed		(DWORD dwSpeed, BOOL bUpdate = TRUE);
    DWORD			GetSpeed		()	{return m_Info.usSpeed;}

    void			SetHealth		(DWORD dwHealth, BOOL fUpdate = TRUE);
    DWORD			GetHealth		()	{return m_Info.usHealth;}

    void			SetSoul			(DWORD dwSoul, BOOL fUpdate = TRUE);
    DWORD			GetSoul			()	{return m_Info.usSoul;}

    void			SetLookFace		(DWORD dwLookFace, BOOL fUpdate = TRUE);
    DWORD			GetLookFace		()	{return m_Info.dwLookface;}

    void			SetHair			(DWORD dwHair, BOOL fUpdate = TRUE);
    DWORD			GetHair			()	{return m_Info.dwHair;}

    void			SetLastLogin	();

    void			SetTaskMask		(DWORD dwMask);
    DWORD			GetTaskMask		()	{ return m_Info.dwTaskMask; }

    //	void			SetVirtue		(DWORD dwVirtue, BOOL bUpdate = TRUE);
    //	DWORD			GetVirtue		()	{ return m_Info.dwVirtue; }

    void			SetHomeID		(OBJID idHome, BOOL bUpdate = TRUE);
    DWORD			GetHomeID		()	{ return m_Info.idHome; }

    void			SetLockKey		(DWORD dwLockKey, BOOL bUpdate = TRUE);
    void			SetCurrLockKey	(DWORD dwLockKey, BOOL bUpdate = TRUE)		{ m_Info.dwCurrLockKey = dwLockKey; }
    DWORD			GetRealLockKey	()	{ return m_Info.dwLockKey; }
    DWORD			GetCurrLockKey	()	{ return m_Info.dwCurrLockKey; }

    int				GetNobilityRank		()	{ return m_Info.ucNobilityRank; }
    void			SetNobilityRank		(DWORD dwNobilityRank, BOOL bUpdate = TRUE);

    void			SetLength		(int nLength, BOOL bUpdate = TRUE);
    int				GetLength		()	{ return m_Info.cLength; }

    void			SetFat			(int nFat, BOOL bUpdate = TRUE);
    int				GetFat			()	{ return m_Info.cFat; }

    void			SetTutorExp		(int nExp, BOOL bUpdate = TRUE);
    void			SetTutorLevel	(UCHAR ucLevel, BOOL bUpdate = TRUE);

    void			SetMaxLifePercent(DWORD dwPercent, BOOL bUpdate = TRUE);
    DWORD			GetMaxLifePercent()	{ return m_Info.dwMaxlifePercent; }

    void			SetMercenaryRank(UCHAR ucRank, BOOL bUpdate = TRUE);
    void			SetMercenaryExp	(DWORD dwExp, BOOL bUpdate = TRUE);

    DWORD			GetExploit		()	{ return m_Info.dwExploit; }
    void			SetExploit		(DWORD dwExploit, BOOL bUpdate = TRUE);

    UserInfoStruct&		GetInfo()	{ return m_Info; }
protected:
    UserInfoStruct		m_Info;
    IRecord*			m_pRes;

    friend class CUser;		// ����������CUser����
};

#endif // !defined(AFX_USERDATA_H__6C3EB549_7325_4A50_82DF_FD07A49E1300__INCLUDED_)
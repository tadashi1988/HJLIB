//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@file
	@brief	HJLib Sample Main
			
	@author {ι Όu
	@date	11/05/24
*/
//	Copyright (C) 2011 HonjoTadashi. All Rights Reserved. 
//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 

#include <core/HJString.h>

namespace{

	//{ι AvP[VΌ
	const hj_tchar oatcApplicationName[] = HJ_T("HJLib Sample");

} // namespace


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@brief	MainClass
	
	@author {ι
*///¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
class clsMain : public hj::clsPfMain
{
	typedef hj::clsPfMain MyClassParent;
public:
	clsMain():MyClassParent(){}
	virtual ~clsMain(){}
	
	virtual	void Update();	//!<{ι [U[pXV
	virtual	void Render();	//!<{ι [U[p`ζ

	//{ι CX^Xν
	virtual	void DeleteInstance(){}
	
	void Init();

private:
	hj::SpTextureResource	m_spTexRes;
	hj::SpHJTexture			m_spTexture;
	hj::SpHJSprite			m_spSprite;
	hj::SpHJSprite			m_spChildSprite;
	hj::SpHJCamera2d		m_spCamera2d;
};

//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@brief	ϊ»
	
	@author {ι
*///¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
void clsMain::Init()
{
	hj::clsHJCoreMgr&	rcCoreMgr	= hj::clsHJCoreMgr::RS();
	hj::SpHJGraphics	spGraphics	= rcCoreMgr.GetGraphics();
	hj::SpHJFileMgr		spFileMgr	= rcCoreMgr.GetFileMgr();

	// eNX`
	m_spTexRes.Reset( NEW hj::clsTextureResource() );
	spFileMgr->RequestLoadResource< hj::clsTextureResource >( HJ_T("test.dds"), m_spTexRes );
	m_spTexture = m_spTexRes->GetTexture();

	// XvCg
	m_spSprite.Reset( NEW hj::clsPfSprite() );
	m_spSprite->SetTexture( m_spTexture );
	m_spSprite->SetPosition(0.f, 0.f);

	// XvCg
	m_spChildSprite.Reset( NEW hj::clsPfSprite() );
	m_spChildSprite->SetTexture( m_spTexture );
	m_spChildSprite->SetPosition(100.0f, 100.0f);
	m_spChildSprite->SetScale(0.5f, 1.0f);
	m_spChildSprite->SetParentSprite( *m_spSprite );

	// J2D
	m_spCamera2d.Reset( NEW hj::clsPfCamera2d() );
	m_spCamera2d->SetPosition(0.f, 0.f);
	m_spCamera2d->SetScreenSize( spGraphics->GetScreenWidth(), spGraphics->GetScreenHeight());
}

//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@brief	[U[pXV
	
	@author {ι
*///¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
void clsMain::Update()
{
	static hj_f32 f32Cnt = 0.0f;
	f32Cnt += 1.0f;
	m_spSprite->SetRotation(f32Cnt * 0.01f);
	m_spSprite->SetPosition( cos(f32Cnt * 0.01f) * 100.0f, 0.0f);

	// qXvCg
	m_spChildSprite->SetRotation(f32Cnt * 0.01f);
}
//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@brief	[U[p`ζ
	
	@author {ι
*///¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
void clsMain::Render()
{
	hj::clsHJCoreMgr&	rcCoreMgr	= hj::clsHJCoreMgr::RS();
	hj::SpHJGraphics	spGraphics	= rcCoreMgr.GetGraphics();
	hj::SpHJDraw2d		spDraw2d	= rcCoreMgr.GetDraw2d();
	
	spGraphics->SetBackColor( hj::HJ_BLACK );
	spGraphics->ClearRenderTarget();
	spGraphics->SetBlendMode( hj::clsHJGraphics::BLEND_BLEND );

	//{ι Έ_obt@Ό«
	static const hj_f32 g_f32OffsetX = 0;
	static const hj_f32 g_f32OffsetY = 0;
	static const hj::clsHJDraw2d::stcFormat_PC g_sTestVertexs[4] = {
		{-100 + g_f32OffsetX, -100 + g_f32OffsetY, 0xFFFF0000},
		{ 100 + g_f32OffsetX, -100 + g_f32OffsetY, 0xFF00FF00},
		{-100 + g_f32OffsetX,  100 + g_f32OffsetY, 0xFF0000FF},
		{ 100 + g_f32OffsetX,  100 + g_f32OffsetY, 0xFFFFFFFF},
	};
	spDraw2d->Begin();
	spDraw2d->RenderArray( hj::clsHJDraw2d::FMT_PC, hj::clsHJDraw2d::PT_TRIANGLESTRIP, g_sTestVertexs, HJ_ARRAY_NUM(g_sTestVertexs));
	spDraw2d->End();

	m_spSprite->Render();
}

//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@brief	WinMainΦ
	
	@author {ι
*///¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT iCmdShow)
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );	// [No

	//{ι ϊ»p[^
	hj::stcPfInitParam sInitParam;
	hj::String::Tcscpy_s( sInitParam.atcApplicationName, HJ_ARRAY_NUM( sInitParam.atcApplicationName ), oatcApplicationName);
	sInitParam.s32ScreenWidth	= 800;
	sInitParam.s32ScreenHeight	= 600;
	sInitParam.bFullScreen		= false;
	sInitParam.hInst			= hInst;
	sInitParam.iCmdShow			= iCmdShow;

	//{ι C
	clsMain	cMain;
	hj_s32 s32Result = 0;

	//{ι ϊ»
	if( cMain.Initialize( sInitParam ) )
	{
		//{ι [U[ϊ»
		cMain.Init();

		//{ι wiF
		hj::SpHJGraphics spGraphics	= hj::clsHJCoreMgr::RS().GetGraphics();
		spGraphics->SetBackColor( hj::HJ_GRAY );

		//{ι [vJn
		s32Result = cMain.StartLoop();
	}

	return s32Result;
}

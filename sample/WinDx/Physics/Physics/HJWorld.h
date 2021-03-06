//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
/*!	@file	HJWorld.h
	@brief	HJ¨GW [h
			
	@author {é ¼u
	@date	14/03/31
*/
//	Copyright (C) 2014 HonjoTadashi. All Rights Reserved. 
//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ 
#ifndef __HJ_PHYSICS_WORLD_H_
#define __HJ_PHYSICS_WORLD_H_

namespace hj{
namespace Physics{

class clsRigitBody;

//! [h
class clsWorld
{
public:
	clsWorld();
	virtual ~clsWorld();

	// --- Static Variable
	static const hj_f32 m_tof32DefaultGravityAccel/* = 9.80665f*/; //<! dÍÁ¬x

	// --- Structure
	//! Wbg{fByA
	struct stcRigitBodyPair{
		hj_s32 s32Index1, s32Index2;
	};
	
	// --- Method
	virtual void Initialize(hj_s32 s32Fps);
	virtual void Update();
	virtual void Render_debug();
	virtual hj_bool RegistRigitBody(clsRigitBody* pcRigitBody);		//<! Wbh{fBo^
	virtual hj_bool UnregistRigitBody(clsRigitBody* pcRigitBody);	//<! Wbh{fBo^ð

	// --- Get
	hj_s32 GetFps()const					{ return m_s32Fps;}					//<! FPSæ¾
	hj_f32 GetGravityAccel()const			{ return m_f32GravityAccel;}		//<! dÍÁ¬xæ¾
	hj_f32 GetGravityAccelFrame()const		{ return m_f32GravityAccelFrame;}	//<! dÍÁ¬x(t[)æ¾
	const hj::stcVector3& GetGravity()const	{ return m_sGravity;}				//<! dÍxNgæ¾

	// --- Set
	void SetFps(hj_s32 s32Fps){ m_s32Fps=s32Fps; UpdateGravityParam(); }										//<! FPSÝè
	void SetGravityAccel(hj_f32 f32GravityAceel){ m_f32GravityAccel=f32GravityAceel; UpdateGravityParam(); }	//<! dÍÁ¬xÝè

private:
	// --- Method
	void UpdateGravityParam(); //<! dÍüèÌp[^XV

	// --- Variable
	static const hj_s32 m_tos32RigitBodyMaxNum = 256;				//<! Wbh{fBÅå
	static const hj_s32 m_tos32RigitBodyPairMaxNum = 1024;			//<! Wbh{fByAÅå
	hj_vector<clsRigitBody*> 		m_vecRigitBody;					//<! Wbh{fBXg
	hj_vector<stcRigitBodyPair> 	m_vecRigitBodyPair;				//<! Wbh{fByAXg
	hj_s32							m_s32Fps;						//<! FPS
	hj_f32							m_f32GravityAccel;				//<! dÍÁ¬x
	hj_f32							m_f32GravityAccelFrame;			//<! dÍÁ¬x(t[)
	hj::stcVector3					m_sGravity;						//<! dÍÁ¬xxNg
};

} // namespace Physics
} // namespace hj

#endif // __HJ_PHYSICS_WORLD_H_

/* TOPPERSカーネルテストスイート
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 *
 *  @(#) $Id: test.c,v 1.0 2004/04/22 00:00:00 morita Exp $
 */

#include <kernel.h>
#include "test.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 76
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CTSK k_ctsk3 = { TA_HLNG|TA_ACT, EXINF_3, TASK3,  ITSKPRI_3, STKSZ, NULL };
T_DTEX k_dtex1 = { TA_HLNG, TEXRTN_1 } ;
T_DTEX k_dtex2 = { TA_HLNG, TEXRTN_2 } ;
T_DTEX e_dtex1 = { TA_HLNG, NULL } ;


void TASK1(VP_INT exinf)
{
	ER ercd ;

									_CHECK_STEP( 19 ) ;
	ercd = dis_dsp() ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = ena_tex() ;

									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	state = sns_tex() ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 51 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	ercd = def_tex( TSK_SELF, NULL ) ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ercd = dis_tex() ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 66 ) ;
	ext_tsk() ;
}

void TEXRTN_1(TEXPTN texptn, VP_INT exinf)
{
	ER ercd ;
	static nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 22 ) ;
		_CHECK_ASSERT( texptn == RASPTN_1111 ) ;
									_CHECK_STEP( 23 ) ;
		_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 24 ) ;
		ercd = ena_dsp() ;
									_CHECK_STEP( 25 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
		state = sns_ctx() ;
									_CHECK_STEP( 27 ) ;
		_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 28 ) ;
		ercd = ref_tex( TASK_ID1, &k_rtex ) ;
									_CHECK_STEP( 29 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
		_CHECK_ASSERT( k_rtex.texstat == TTEX_DIS ) ;
									_CHECK_STEP( 31 ) ;
		_CHECK_ASSERT( k_rtex.pndptn == 0 ) ;
									_CHECK_STEP( 32 ) ;
		ercd = slp_tsk() ;

									_CHECK_STEP( 43 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
		return ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 45 ) ;
		_CHECK_ASSERT( texptn == RASPTN_AAAE ) ;
									_CHECK_STEP( 46 ) ;
		_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 47 ) ;
		return ;
	}
	else {
	}
}

void TEXRTN_2(TEXPTN texptn, VP_INT exinf)
{
									_CHECK_STEP( 58 ) ;
		_CHECK_ASSERT( texptn == RASPTN_1 ) ;
									_CHECK_STEP( 59 ) ;
		_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 60 ) ;
		return ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = def_tex( ERR_TASK_ID, &k_dtex1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = def_tex( TASK_ID3, &k_dtex1 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 5 ) ;
#ifdef ERR_POINTER
	pk_dtex = ERR_POINTER ;
									_CHECK_STEP( 6 ) ;
	ercd = def_tex( E_TASK_ID1, pk_dtex ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 6 ) ;
									_CHECK_STEP( 7 ) ;
#endif
									_CHECK_STEP( 8 ) ;
	k_dtex = e_dtex1;
	k_dtex.texatr = ERR_TEXATR;
									_CHECK_STEP( 9 ) ;
	ercd = def_tex( E_TASK_ID1, &k_dtex ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 11 ) ;
#ifdef ERR_POINTER
	k_dtex = e_dtex1;
	k_dtex.texrtn = ERR_POINTER;
									_CHECK_STEP( 12 ) ;
	ercd = def_tex( E_TASK_ID1, &k_dtex ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 12 ) ;
									_CHECK_STEP( 13 ) ;
#endif
									_CHECK_STEP( 14 ) ;
	ercd = def_tex( TASK_ID1, &k_dtex1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_1111 ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ercd = chg_pri( TASK_ID1, ITSKPRI_1 ) ;

									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_AAAA ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_4 ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = ref_tex( TASK_ID1, &k_rtex ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( k_rtex.texstat == TTEX_DIS ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( k_rtex.pndptn == RASPTN_AAAE ) ;
									_CHECK_STEP( 42 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_1 ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = def_tex( TASK_ID1, &k_dtex2 ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 68 ) ;
	ercd = def_tex( TASK_ID1, &k_dtex1 ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_1111 ) ;
									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 72 ) ;
	ercd = cre_tsk( TASK_ID3, &k_ctsk3 ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 74 ) ;
	ercd = ref_tex( TASK_ID3, &k_rtex ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ext_tsk() ;
}


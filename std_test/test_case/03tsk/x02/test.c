/* TOPPERSカーネルテストスイート
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation
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
#include "test_x02.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 49
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB stk[STKSZ];

T_CTSK k_ctsk1 = { TA_HLNG        , EXINF_1, TASK1,  ITSKPRI_1, STKSZ, NULL };
T_CTSK k_ctsk2 = { TA_HLNG|TA_ACT , EXINF_2, TASK2,  ITSKPRI_2, STKSZ, stk };
T_CTSK e_ctsk1 = { TA_HLNG        , EXINF_1, TASK16, ITSKPRI_3, STKSZ/8, NULL };

ER_ID tskid1=2,tskid2=3;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 25 ) ;
	p_stk = _read_sp() ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( is_bufmgr_buffer( p_stk ) == TRUE ) ;
									_CHECK_STEP( 27 ) ;
	actcnt = can_act( TSK_SELF ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( actcnt == 0 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = ras_tex( TSK_SELF, RASPTN_1 ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	VP p_stk;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( exinf == EXINF_2 ) ;
									_CHECK_STEP( 35 ) ;
	p_stk = _read_sp() ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( p_stk > stk && p_stk < &stk[STKSZ] ) ;
									_CHECK_STEP( 37 ) ;
	ercd = get_pri( TSK_SELF, p_tskpri ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( tskpri == ITSKPRI_2 ) ;
									_CHECK_STEP( 40 ) ;
	wupcnt = can_wup( TSK_SELF ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( wupcnt == 0 ) ;
									_CHECK_STEP( 42 ) ;
	ercd = rsm_tsk( tskid2 ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	INT tskid_count = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_ctsk = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_tsk( pk_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.tskatr = ERR_TASKATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	k_ctsk = e_ctsk1 ;
	k_ctsk.task = ERR_POINTER ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.itskpri = ERR_ITSKPRI ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.stksz = ERR_STKSZ ;
									_CHECK_STEP( 14 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT( MERCD( ercd ) == E_PAR || MERCD( ercd ) == E_NOMEM) ;
									_CHECK_STEP( 16 ) ;
#ifdef ERR_POINTER
	k_ctsk = e_ctsk1 ;
	k_ctsk.stk = ERR_POINTER ;
									_CHECK_STEP( 17 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 17 ) ;
									_CHECK_STEP( 18 ) ;
#endif
									_CHECK_STEP( 19 ) ;
	tskid1 = acre_tsk( &k_ctsk1 ) ;
	if ( tskid1 > 0 ) tskid_count++;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( tskid1 == 2 ) ;
_PRINT_VER( tskid1 ) ;
									_CHECK_STEP( 21 ) ;
	ercd = get_pri( tskid1, p_tskpri ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = act_tsk( tskid1 ) ;

									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	tskid2 = acre_tsk( &k_ctsk2 ) ;
	if ( tskid2 > 0 ) tskid_count++;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( tskid2 == 3 ) ;
_PRINT_VER( tskid2 ) ;
									_CHECK_STEP( 46 ) ;
	k_ctsk = e_ctsk1 ;
									_CHECK_STEP( 47 ) ;
	while ( tskid_count <= ACRE_CNT ) {
		ercd = acre_tsk( &k_ctsk ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) tskid_count++;
		else break;
	}
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ext_tsk() ;
}

void TASK16(VP_INT exinf)
{
	ext_tsk() ;
}

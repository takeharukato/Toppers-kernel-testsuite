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
#define _LAST_STEP 67
#define _NEED_TEST_ROUTINES
#include "test_com.h"
#include "hw_routines.h"

void TASK1(VP_INT exinf)
{
									_CHECK_STEP( 41 ) ;
	actcnt = can_act( TSK_SELF ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( actcnt == 1 ) ;
									_CHECK_STEP( 43 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	PREPARE_SW_DELAY( DLYTIM_20 ) ;
									_CHECK_STEP( 1 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 3 ) ;
	ercd = dis_dsp() ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 5 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 7 ) ;
	ercd = pol_sem( SEM_ID1 ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 9 ) ;
	ercd = get_tid( p_tskid ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( tskid == TASK_ID2 ) ;
									_CHECK_STEP( 12 ) ;
	ercd = loc_cpu() ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 16 ) ;
	ercd = unl_cpu() ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 20 ) ;
	RAISE_INTERRUPT() ;
									_CHECK_STEP( 22 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 24 ) ;
	ercd = sta_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
	SW_DELAY() ;
									_CHECK_STEP( 30 ) ;
	ercd = stp_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 34 ) ;
	ercd = ena_tex() ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = ras_tex( TASK_ID2, RASPTN_2 ) ;
									_CHECK_STEP( 38 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 40 ) ;
	ercd = ena_dsp() ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 45 ) ;
	RAISE_INTERRUPT() ;
									_CHECK_STEP( 47 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 49 ) ;
	ercd = sta_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = dly_tsk( DLYTIM_20 ) ;
									_CHECK_STEP( 52 ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 56 ) ;
	ercd = ras_tex( TASK_ID2, RASPTN_2 ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 61 ) ;
	ercd = loc_cpu() ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 65 ) ;
	ercd = unl_cpu() ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	ext_tsk() ;
}

void TEXRTN_2(TEXPTN texptn, VP_INT exinf)
{
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 37 ) ;
		return ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 57 ) ;
		return ;
	}
	else {
									_CHECK_STEP( -1 ) ;
		return ;
	}
}

void INTHDR_1( void )
{
	static int nCount = 0 ;
	CLEAR_INTERRUPT() ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 21 ) ;
		return ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 46 ) ;
		return ;
	}
	else {
									_CHECK_STEP( -1 ) ;
		return ;
	}
}

void CYCHDR_1(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 27 ) ;
		ercd = iact_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 28 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
		return ;
	}
	else {
		return ;
	}
}


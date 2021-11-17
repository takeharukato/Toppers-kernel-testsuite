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
#include "test_x03.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 18
#define _NEED_TEST_ROUTINES
#include "test_com.h"
#include "hw_routines.h"

void dummy();

T_CISR k_cisr1 = { TA_HLNG , EXINF_1 , INTNO_1 , ISR_1  } ;
T_CISR e_cisr1 = { TA_HLNG , EXINF_1 , INTNO_1 , (FP)dummy  } ;

ER_ID isr_id1 ;

void TASK1(VP_INT exinf)
{
	ER ercd;
	UINT  isrid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cisr = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_isr( pk_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cisr = e_cisr1 ;
	k_cisr.isratr = ERR_ISRATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_isr( &k_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_INTNO
	k_cisr = e_cisr1 ;
	k_cisr.intno = ERR_INTNO ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_isr( &k_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
#ifdef ERR_POINTER
	k_cisr = e_cisr1 ;
	k_cisr.isrhdr =  ERR_POINTER ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_isr( &k_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 11 ) ;
									_CHECK_STEP( 12 ) ;
#endif
									_CHECK_STEP( 13 ) ;

	isr_id1 = acre_isr( &k_cisr1 ) ;
	if ( isr_id1 > 0 ) isrid_cnt++;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( isr_id1 > 0 ) ;
									_CHECK_STEP( 15 ) ;
//	RAISE_INTERRUPT() ;
									_CHECK_STEP( 16 ) ;
	while ( isrid_cnt <= ACRE_CNT ) {
		ercd = acre_isr( &k_cisr1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) isrid_cnt++;
		else break;
		}
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ext_tsk() ;
}

void ISR_1(VP_INT exinf)
{
	_CHECK_ASSERT( exinf == EXINF_1 ) ;
}

void dummy( VP_INT exinf )
{
}


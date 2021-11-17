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

#include <stdio.h>

#define _TEST_TIME 2  
#define _LAST_STEP 35
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;

	                                                                _CHECK_STEP( 1 ) ;
	/* msg1-msg16 is static variables */
									_CHECK_STEP( 2 ) ;
	msg16.msgpri = MSGPRI_16 ;
									_CHECK_STEP( 3 ) ;
	ercd = snd_mbx( MBX_ID1, &msg16 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 5 ) ;
	msg8.msgpri = MSGPRI_8 ;
									_CHECK_STEP( 6 ) ;
	ercd = snd_mbx( MBX_ID1, &msg8 ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 8 ) ;
	msg1.msgpri = MSGPRI_1 ;
									_CHECK_STEP( 9 ) ;
	ercd = snd_mbx( MBX_ID1, &msg1 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 11 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
									_CHECK_STEP( 12 ) ;

	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
									_CHECK_STEP( 13 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
									_CHECK_STEP( 14 ) ;
	ext_tsk() ;
}

void TASK5(VP_INT exinf)
{
									_CHECK_STEP( 15 ) ;
	ext_tsk() ;
}

void TASK6(VP_INT exinf)
{
									_CHECK_STEP( 16 ) ;
	ext_tsk() ;
}

void TASK7(VP_INT exinf)
{
									_CHECK_STEP( 17 ) ;
	ext_tsk() ;
}

void TASK8(VP_INT exinf)
{
									_CHECK_STEP( 18 ) ;
	ext_tsk() ;
}

void TASK9(VP_INT exinf)
{
									_CHECK_STEP( 19 ) ;
	ext_tsk() ;
}

void TASK10(VP_INT exinf)
{
									_CHECK_STEP( 20 ) ;
	ext_tsk() ;
}

void TASK11(VP_INT exinf)
{
									_CHECK_STEP( 21 ) ;
	ext_tsk() ;
}

void TASK12(VP_INT exinf)
{
									_CHECK_STEP( 22 ) ;
	ext_tsk() ;
}

void TASK13(VP_INT exinf)
{
									_CHECK_STEP( 23 ) ;
	ext_tsk() ;
}

void TASK14(VP_INT exinf)
{
									_CHECK_STEP( 24 ) ;
	ext_tsk() ;
}

void TASK15(VP_INT exinf)
{
									_CHECK_STEP( 25 ) ;
	ext_tsk() ;
}

void TASK16(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 26 ) ;
	ercd = prcv_mbx( MBX_ID1, &pk_msg ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( pk_msg == &msg1 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = prcv_mbx( MBX_ID1, &pk_msg ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( pk_msg == &msg8 ) ;
									_CHECK_STEP( 32 ) ;
	ercd = prcv_mbx( MBX_ID1, &pk_msg ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( pk_msg == &msg16 ) ;
									_CHECK_STEP( 35  ) ;
	ext_tsk() ;
}


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

#define _TEST_TIME 3
#define _LAST_STEP 97
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 53 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_1111 ) ;
									_CHECK_STEP( 66 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0000, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 68 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_AAAA, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_AAAA ) ;
									_CHECK_STEP( 71 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 74 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_0002 ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0002 ) ;
									_CHECK_STEP( 79 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 81 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_8000, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 84 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_8000 ) ;
									_CHECK_STEP( 86 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_8000, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 87 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 88 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_5555 ) ;
									_CHECK_STEP( 89 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 90 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_5555, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 91 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 92 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_5555 ) ;
									_CHECK_STEP( 93 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_5555, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 94 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 95 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = set_flg( ERR_FLG_ID, SETPTN_1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_SETPTN
	ercd = set_flg( FLG_ID1, ERR_SETPTN ) ;
#endif
									_CHECK_STEP( 4 ) ;
#ifdef ERR_SETPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 5 ) ;
	ercd = clr_flg( ERR_FLG_ID, SETPTN_1 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_CLRPTN
	ercd = clr_flg( FLG_ID1, ERR_CLRPTN ) ;
#endif
									_CHECK_STEP( 8 ) ;
#ifdef ERR_CLRPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 9 ) ;
	ercd = wai_flg( ERR_FLG_ID, WAIPTN_1, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 11 ) ;
#ifdef ERR_WAIPTN
	ercd = wai_flg( FLG_ID1, ERR_WAIPTN, TWF_ORW, p_flgptn ) ;
#endif
									_CHECK_STEP( 12 ) ;
#ifdef ERR_WAIPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 13 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_1, ERR_WFMODE, p_flgptn ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
#ifdef ERR_POINTER
	ercd = wai_flg( FLG_ID1, WAIPTN_1, TWF_ANDW, ERR_POINTER ) ;
#endif
									_CHECK_STEP( 16 ) ;
#ifdef ERR_POINTER
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 17 ) ;
	ercd = pol_flg( ERR_FLG_ID, WAIPTN_1, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 19 ) ;
#ifdef ERR_WAIPTN
	ercd = pol_flg( FLG_ID1, ERR_WAIPTN, TWF_ORW, p_flgptn ) ;
#endif
									_CHECK_STEP( 20 ) ;
#ifdef ERR_WAIPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 21 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_1, ERR_WFMODE, p_flgptn ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 23 ) ;
#ifdef ERR_POINTER
	ercd = pol_flg( FLG_ID1, WAIPTN_1, TWF_ANDW, ERR_POINTER ) ;
#endif
									_CHECK_STEP( 24 ) ;
#ifdef ERR_POINTER
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 25 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_5555 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = set_flg( FLG_ID2, SETPTN_AAAA ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_AAAA ) ;
									_CHECK_STEP( 32 ) ;
	ercd = pol_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = clr_flg( FLG_ID1, CLRPTN_0000 ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0000, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_0055 ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0050, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0055 ) ;
									_CHECK_STEP( 45 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_5500 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0055, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_5555 ) ;
									_CHECK_STEP( 50 ) ;
	ercd = clr_flg( FLG_ID1, CLRPTN_0000 ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = rel_wai( TASK_ID1 ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_1111 ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_8000 ) ;
									_CHECK_STEP( 96 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 97 ) ;
	ext_tsk() ;
}


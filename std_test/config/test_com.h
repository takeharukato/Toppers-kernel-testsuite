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
 */

/******************************************************************
***																***
***		Name:	Common definitions for standard profile test    ***
***																***
*************************<< Function >>****************************
***																***
***																***
***																***
******************************************************************/

#ifndef _TEST_COM_H_
#define _TEST_COM_H_

/******************************************************************
*******************************************************************
***																***
***		Constants definition									***
***																***
*******************************************************************
******************************************************************/

/*************************************/
/**	Task exception paterns  		**/
/*************************************/
#define RASPTN_1      0x0001
#define RASPTN_2      0x0002
#define RASPTN_4      0x0004
#define RASPTN_1111   0x1111
#define RASPTN_55AA   0x55AA
#define RASPTN_AA55   0xAA55
#define RASPTN_AAAA   0xAAAA
#define RASPTN_AAAE   0xAAAE
#define RASPTN_FFFF   0xFFFF

/*************************************/
/**	Extended informations   		**/
/*************************************/
#define EXINF_1       (VP_INT)0x00000001
#define EXINF_1_1     (VP_INT)0x00000011
#define EXINF_1_2     (VP_INT)0x00000012
#define EXINF_2       (VP_INT)0x00000002
#define EXINF_2_1     (VP_INT)0x00000021
#define EXINF_2_2     (VP_INT)0x00000022
#define EXINF_3       (VP_INT)0x00000003
#define EXINF_4       (VP_INT)0x00000004
#define EXINF_5       (VP_INT)0x00000005
#define EXINF_6       (VP_INT)0x00000006
#define EXINF_7       (VP_INT)0x00000007
#define EXINF_8       (VP_INT)0x00000008
#define EXINF_9       (VP_INT)0x00000009
#define EXINF_10      (VP_INT)0x0000000A
#define EXINF_11      (VP_INT)0x0000000B
#define EXINF_12      (VP_INT)0x0000000C
#define EXINF_13      (VP_INT)0x0000000D
#define EXINF_14      (VP_INT)0x0000000E
#define EXINF_15      (VP_INT)0x0000000F
#define EXINF_16      (VP_INT)0x00000010
#define EXINF_CYC1    (VP_INT)0x00000001
#define EXINF_CYC2    (VP_INT)0x00000002

/*************************************/
/**	Initial values  				**/
/*************************************/
#define IFLGPTN_0     0x0000
#define IFLGPTN_1     0x0001
#define IFLGPTN_2     0x0002
#define IFLGPTN_3     0x0003
#define IFLGPTN_4     0x0004
#define IFLGPTN_5     0x0005
#define IFLGPTN_6     0x0006
#define IFLGPTN_7     0x0007
#define IFLGPTN_8     0x0008
#define ISEMCNT_0     0
#define ISEMCNT_1     1
#define ISEMCNT_2     2
#define ISEMCNT_FFFE  0xfffe

/*************************************/
/**	startup address 				**/
/*************************************/
#define TASK1         task1
#define TASK1_1       task1_1
#define TASK1_2       task1_2
#define TASK2         task2
#define TASK2_1       task2_1
#define TASK2_2       task2_2
#define TASK3         task3
#define TASK4         task4
#define TASK5         task5
#define TASK6         task6
#define TASK7         task7
#define TASK8         task8
#define TASK9         task9
#define TASK10        task10
#define TASK11        task11
#define TASK12        task12
#define TASK13        task13
#define TASK14        task14
#define TASK15        task15
#define TASK16        task16
#define TEXRTN_1      texrtn_1
#define TEXRTN_2      texrtn_2
#define INTHDR_1      inthdr_1
#define ISR_ADR_0     (FP)0
#define ISR_1         isr_1
#define EXCHDR_1      exchdr_1
#define EXCHDR_2      exchdr_2
#define INIRTN_1      inirtn_1
#define INIRTN_2      inirtn_2
#define CYCHDR_1      cychdr_1
#define CYCHDR_2      cychdr_2
//#define EXCNO_1       1
#define EXCNO_1		  224		/* ロードエラー例外 */
#define EXCNO_2       2
//#define INTNO_1       1

/*************************************/
/**	Priorities  					**/
/*************************************/
#define ITSKPRI_1     0x0001
#define ITSKPRI_2     0x0002
#define ITSKPRI_3     0x0003
#define ITSKPRI_4     0x0004
#define ITSKPRI_5     0x0005
#define ITSKPRI_6     0x0006
#define ITSKPRI_7     0x0007
#define ITSKPRI_8     0x0008
#define ITSKPRI_9     0x0009
#define ITSKPRI_10    0x000a
#define ITSKPRI_11    0x000b
#define ITSKPRI_12    0x000c
#define ITSKPRI_13    0x000d
#define ITSKPRI_14    0x000e
#define ITSKPRI_15    0x000f
#define ITSKPRI_16    0x0010
#define TSKPRI_1      0x0001
#define TSKPRI_2      0x0002
#define TSKPRI_3      0x0003
#define TSKPRI_4      0x0004
#define MSGPRI_1      0x0001
#define MSGPRI_2      0x0002
#define MSGPRI_3      0x0003
#define MSGPRI_4      0x0004
#define MSGPRI_5      0x0005
#define MSGPRI_6      0x0006
#define MSGPRI_7      0x0007
#define MSGPRI_8      0x0008
#define MSGPRI_9      0x0009
#define MSGPRI_10     0x000a
#define MSGPRI_11     0x000b
#define MSGPRI_12     0x000c
#define MSGPRI_13     0x000d
#define MSGPRI_14     0x000e
#define MSGPRI_15     0x000f
#define MSGPRI_16     0x0010
#define MAXMPRI_0     0x00000000
#define MAXMPRI_3     0x00000003
#define MAXMPRI_5     0x00000005
#define MAXMPRI_16    0x00000010

/*************************************/
/**	Attributes  					**/
/*************************************/
#define INHATR        TA_HLNG
#define INHATR_1      TA_HLNG
#define EXCATR        TA_HLNG

/*************************************/
/**	Sizes   						**/
/*************************************/
#define STKSZ         0x0500
#define BLKSZ_0       0
#define BLKSZ_10      10
#define BLKSZ_256     256

/*************************************/
/**	Timeout values  				**/
/*************************************/
#define TMO_1         1
#define TMO_2         2
#define TMO_10        10
#define TMO_100       100
#define TMO_200       200
#define DLYTIM_2      2
#define DLYTIM_5      5
#define DLYTIM_10     10
#define DLYTIM_16     16
#define DLYTIM_20     20
#define DLYTIM_50     50
#define DLYTIM_100    100
#define DLYTIM_300    300
#define DLYTIM_500    500
#define DLYTIM_1000   1000
#define SYSTIM_0      0
#define SYSTIM_50     50
#define SYSTIM_1000   1000

/*************************************/
/**	Cyclic time value   			**/
/*************************************/
#define CYCTIM_0      0
#define CYCTIM_10     10
#define CYCTIM_55     55
#define CYCPHS_0      0
#define CYCPHS_5      5

/*************************************/
/**	Maximum values  				**/
/*************************************/
#define MAXSEM_1      1
#define MAXSEM_2      2
#define MAXSEM_FFFF   0xffff

/*************************************/
/**	Flag paterns					**/
/*************************************/
#define SETPTN_1      0x0001
#define CLRPTN_0000   0x0000
#define CLRPTN_1      0x0001
#define SETPTN_0001   0x0001
#define SETPTN_0002   0x0002
#define SETPTN_0005   0x0005
#define SETPTN_0055   0x0055
#define SETPTN_0500   0x0500
#define SETPTN_0505   0x0505
#define SETPTN_5500   0x5500
#define SETPTN_1111   0x1111
#define SETPTN_5555   0x5555
#define SETPTN_8000   0x8000
#define SETPTN_AAAA   0xAAAA
#define WAIPTN_0000   0x0000
#define WAIPTN_1      0x0001
#define WAIPTN_0001   0x0001
#define WAIPTN_0002   0x0002
#define WAIPTN_0005   0x0005
#define WAIPTN_0010   0x0010
#define WAIPTN_0020   0x0020
#define WAIPTN_0050   0x0050
#define WAIPTN_0055   0x0055
#define WAIPTN_0505   0x0505
#define WAIPTN_5500   0x5500
#define WAIPTN_5555   0x5555
#define WAIPTN_8000   0x8000
#define WAIPTN_AAAA   0xAAAA
#define FLGPTN_0055   0x0055
#define FLGPTN_5555   0x5555

/*************************************/
/**	Others  						**/
/*************************************/
#define DATA_00       (VP_INT)0x00000000
#define DATA_01       (VP_INT)0x00000001
#define DATA_02       (VP_INT)0x00000002
#define DATA_03       (VP_INT)0x00000003
#define DATA_04       (VP_INT)0x00000004
#define DATA_05       (VP_INT)0x00000005
#define DATA_11       (VP_INT)0x00000011
#define DATA_22       (VP_INT)0x00000022
#define DATA_33       (VP_INT)0x00000033
#define DATA_44       (VP_INT)0x00000044
#define DATA_55       (VP_INT)0x00000055
#define DATA_66       (VP_INT)0x00000066
#define DATA_77       (VP_INT)0x00000077
#define DATA_88       (VP_INT)0x00000088
#define DATA_99       (VP_INT)0x00000099
#define DATA_AA       (VP_INT)0x000000AA
#define DATA_CC       (VP_INT)0x000000CC
#define DATA_DD       (VP_INT)0x000000DD
#define DATA_EE       (VP_INT)0x000000EE
#define DATA_FF       (VP_INT)0x000000FF
#define MEMORY        ((VP_INT)p_memory)

/*************************************/
/**	Counters						**/
/*************************************/
#define DTQCNT_0      0x00000000
#define DTQCNT_1      0x00000001
#define DTQCNT_2      0x00000002
#define DTQCNT_MAX    0x07ffffff
#define BLKCNT_0      0
#define BLKCNT_1      1
#define BLKCNT_10     10
#define BLKCNT_2048   2048

/*************************************/
/**	Error constants 				**/
/*************************************/
#define ERR_TASK      not_exist_function
#define ERR_TASK_ID   -1
#define ERR_TASKATR   0xff
#define ERR_ITSKPRI   -1
#define ERR_TSKPRI    -2
#define ERR_STKSZ     999999
#define ERR_TMO       -2
//#define ERR_DLYTIM    0x20000
#define ERR_TEXATR    0xff
#define ERR_TEXRTN    not_exist_function
#define ERR_RASPTN    0
//#define ERR_INHNO     17
#define ERR_INHATR    0xff
#define ERR_ISRATR    2
//#define ERR_INTNO     99
//#define ERR_EXCNO     -1
//#define ERR_EXCATR    0xff
#define ERR_SEMATR    0x55
#define ERR_SEM_ID    -2
#define MAXSEM_OVER   0x20000
#define ERR_FLG_ID    -3
#define ERR_FLGATR    0xaa
//#define ERR_IFLGPTN   0x10000
//#define ERR_SETPTN    0xffffffff
//#define ERR_CLRPTN    0xffffffff
//#define ERR_WAIPTN    0xffffffff
#define ERR_WFMODE    0x02
//#define ERR_POINTER   0x0000
#define ERR_DTQ_ID     -2
#define ERR_DTQATR    0xaa
//#define ERR_DTQCNT    0xffffffff
#define ERR_MBX_ID     -1
#define ERR_MBXATR    0xbb
#define ERR_MAXMPRI   0xffffffff
#define ERR_MSGPRI    -1
#define ERR_MPF_ID     -3
#define ERR_MPFATR    0xcc
//#define ERR_SYSTIM    -1
#define ERR_CYC_ID     0
#define ERR_CYCATR    0xdd
#define ERR_CYCPHS    0xffffffff
#define ERR_INTHDR    not_exist_function
#define ERR_EXCHDR    not_exist_function
#define ERR_CYCHDR    not_exist_function

/*************************************************
*
*    ITRON4.0 フルセット対応 追加分
*
***************************************************/

#define ALMHDR_1      almhdr_1
#define ALMHDR_2      almhdr_2
#define OVRHDR_1      ovrhdr_1
#define OVRHDR_2      ovrhdr_2

#define FNCD_1        1
#define FNCD_2        2
#define SVCRTN_1      svcrtn_1
#define SVCRTN_2      svcrtn_2

#define ERR_MTX_ID    -2
#define ERR_MTXATR    0xff
#define ERR_MBF_ID    -2
#define ERR_MBFATR    0xff
#define ERR_POR_ID    -2
#define ERR_PORATR    0xff
#define ERR_MPL_ID    -2
#define ERR_MPLATR    0xff
#define ERR_ALM_ID    -2
#define ERR_ALMATR    0xff
#define ERR_OVRATR    2
#define ERR_ISR_ID    -2
//#define ERR_FNCD      99    /* 実装依存 */
#define ERR_SVCATR    0xff

#define ERR_CEILPRI   0xffffffff
#define ERR_MAXMSZ    0xffffffff
#define ERR_MBFSZ     0xffffffff
//#define ERR_MAXCMSZ   0xffffffff    /* 実装依存 */
//#define ERR_MAXRMSZ   0xffffffff    /* 実装依存 */
#define ERR_CMSGSZ    0xffffffff
#define ERR_RMSGSZ    0xffffffff
#define ERR_RDVNO     0xffffffff

#define ERR_MPLBLK    (VP)0xffffffff
#define ERR_ALMTIM    0xffffffff
//#define ERR_OVRTIM    0xffffffff    /* 実装依存 */

//efine ERR_    not_exist_function
#define ERR_MPL       not_exist_function
#define ERR_ISR       not_exist_function
#define ERR_ALMHDR    not_exist_function
#define ERR_OVRHDR    not_exist_function
#define ERR_SVCRTN    not_exist_function

#define MPLSZ_0      0
#define MPLSZ_10     10
#define MPLSZ_128    128
#define MPLSZ_256    256
#define MPLSZ_4K     4096

#define MAXMSZ       128
#define MSGSZ_0      0
#define MSGSZ_10     10
#define MSGSZ_256    256

#define MBFSZ_0      0
#define MBFSZ_256    256
#define MBFSZ_4K     4096

#define RDVPTN_0     0x0000
#define RDVPTN_1     0x0001
#define RDVMSZ       256

#define OVRTIM_UNIT  151516   /* 100ms / 0.66μs */
#define OVRTIM_50    5 * OVRTIM_UNIT
#define OVRTIM_1000  100 * OVRTIM_UNIT

#define SVC_RDATA_11  (ER_UINT)11
#define SVC_RDATA_22  (ER_UINT)22

#define INHNO_TMU1    0x420		/* TMU1 */
#define INHNO_TMU2    0x440		/* TMU2 */
#define INHNO_1       INHNO_TMU2

#define INTNO_1       INHNO_TMU2

/*************************************/
/**	Use delayed service call for	**/
/**		non task context			**/
/*************************************/
//#define USE_DELAYED_SVC

/******************************************************************
*******************************************************************
***																***
***		Function protptype definitions for configuration		***
***																***
*******************************************************************
******************************************************************/

#ifndef _MACRO_ONLY

void task1(VP_INT exinf);
void task1_1(VP_INT exinf);
void task1_2(VP_INT exinf);
void task2(VP_INT exinf);
void task2_1(VP_INT exinf);
void task2_2(VP_INT exinf);
void task3(VP_INT exinf);
void task4(VP_INT exinf);
void task5(VP_INT exinf);
void task6(VP_INT exinf);
void task7(VP_INT exinf);
void task8(VP_INT exinf);
void task9(VP_INT exinf);
void task10(VP_INT exinf);
void task11(VP_INT exinf);
void task12(VP_INT exinf);
void task13(VP_INT exinf);
void task14(VP_INT exinf);
void task15(VP_INT exinf);
void task16(VP_INT exinf);
void texrtn_1(TEXPTN texptn, VP_INT exinf);
void texrtn_2(TEXPTN texptn, VP_INT exinf);
void inthdr_1( void ) ;
void isr_1(VP_INT exinf);
void exchdr_1(VP p_excinf);
void exchdr_2(VP p_excinf);
void inirtn_1(VP_INT exinf);
void inirtn_2(VP_INT exinf);
void cychdr_1(VP_INT exinf);
void cychdr_2(VP_INT exinf);

/*************************************************
*
*    ITRON4.0 フルセット対応 追加分
*
***************************************************/
#ifndef __JSP

void almhdr_1(VP_INT exinf);
void almhdr_2(VP_INT exinf);
void ovrhdr_1(ID taskid, VP_INT exinf);
void ovrhdr_2(ID taskid, VP_INT exinf);

ER_UINT  svcrtn_1(VP_INT arg1, VP_INT arg2, VP_INT arg3, VP_INT arg4, VP_INT arg5 );
ER_UINT  svcrtn_2(VP_INT arg1, VP_INT arg2, VP_INT arg3, VP_INT arg4, VP_INT arg5 );

#endif

#endif /* _MACRO_ONLY */

#ifdef _NEED_TEST_ROUTINES

#include <stdio.h>

/******************************************************************
*******************************************************************
***																***
***		Global variables										***
***																***
*******************************************************************
******************************************************************/

/*************************************************
*
*    ITRON4.0 フルセット対応 追加分
*
***************************************************/
#ifndef __JSP

T_CTSK k_ctsk, *pk_ctsk;
T_RTSK k_rtsk, *pk_rtsk;
T_RTST k_rtst, *pk_rtst;
T_DTEX k_dtex, *pk_dtex;
T_RTEX k_rtex, *pk_rtex;
T_CSEM k_csem, *pk_csem;
T_RSEM k_rsem, *pk_rsem;
T_CFLG k_cflg, *pk_cflg;
T_RFLG k_rflg, *pk_rflg;
T_CDTQ k_cdtq, *pk_cdtq;
T_RDTQ k_rdtq, *pk_rdtq;
T_CMBX k_cmbx, *pk_cmbx;
T_RMBX k_rmbx, *pk_rmbx;
T_CMTX k_cmtx, *pk_cmtx;
T_RMTX k_rmtx, *pk_rmtx;
T_CMBF k_cmbf, *pk_cmbf;
T_RMBF k_rmbf, *pk_rmbf;
T_CPOR k_cpor, *pk_cpor;
T_RPOR k_rpor, *pk_rpor;
T_RRDV k_rrdv, *pk_rrdv;
T_CMPF k_cmpf, *pk_cmpf;
T_RMPF k_rmpf, *pk_rmpf;
T_CMPL k_cmpl, *pk_cmpl;
T_RMPL k_rmpl, *pk_rmpl;
T_CCYC k_ccyc, *pk_ccyc;
T_RCYC k_rcyc, *pk_rcyc;
T_CALM k_calm, *pk_calm;
T_RALM k_ralm, *pk_ralm;
T_CISR k_cisr, *pk_cisr;
T_RISR k_risr, *pk_risr;
T_DOVR k_dovr, *pk_dovr;
T_ROVR k_rovr, *pk_rovr;
T_DSVC k_dsvc, *pk_dsvc;
T_RVER k_rver, *pk_rver;

VB rdv_msg1[] = "rdv msg 1" ;
VB rdv_msg2[] = "RDV MSG" ;

volatile UW alm_work1 ;
volatile UW alm_work2 ;

volatile UW ovr_work1 ;
volatile UW ovr_work2 ;
volatile UW ovr_work3 ;
volatile UW ovr_work11 ;
volatile UW ovr_work12 ;

VP p_stk;
#endif

T_MSG_PRI msg1 ;
T_MSG_PRI msg2 ;
T_MSG_PRI msg21 ;
T_MSG_PRI msg22 ;
T_MSG_PRI msg3 ;
T_MSG_PRI msg8 ;
T_MSG_PRI msg16 ;
T_MSG_PRI *pk_msg, **ppk_msg = &pk_msg ;
//ER ercd ;					/* this should be local variable */
//VP_INT exinf ;			/* this should be local variable */
BOOL state ;
ER_UINT actcnt ;
ID tskid, *p_tskid = &tskid ;
PRI tskpri, *p_tskpri = &tskpri ;
ER_UINT wupcnt ;
FLGPTN flgptn, *p_flgptn = &flgptn ;
TEXPTN tecptn ;
VP_INT data, *p_data = &data ;
//VP blk, *p_blk = &blk ;	/* this should be local variable */
SYSTIM systim, *p_systim = &systim ;
SYSTIM systim1 ;
SYSTIM systim2 ;
volatile UW cyc_work1 ;
volatile UW cyc_work2 ;
UW work ;
B b1 ;
H h1 ;
W w1 ;
UB ub1 ;
UH uh1 ;
UW uw1 ;
VB vb1 ;
VH vh2 ;
VW vw1 ;
VP vp ;
FP fp ;
INT int1 ;
UINT uint1 ;
BOOL bool1 ;
FN fn1 ;
ER er1 ;
ID id1 ;
ATR atr1 ;
STAT stat1 ;
MODE mode1 ;
PRI pri1 ;
SIZE size1 ;
TMO tmo1 ;
RELTIM reltim1 ;
VP_INT vp_int1 ;
ER_BOOL er_bool1 ;
ER_ID er_id1 ;
ER_UINT er_uint1 ;
char* p_memory = "MEMORY" ;

BOOL bTestIllegalSequence=FALSE;
int nTestCurrentStep=0;
BOOL bTestAssertOccured = FALSE ;

char* _convert_ERROR( ER ercd );

#define _CHECK_STEP( n )  _test_check_step( n )
#define _CHECK_STEP_( n )  _test_check_step_( n )
#define _CHECK_ASSERT( cond ) { if ( !( cond ) ) _test_assert( #cond ) ; }

#define PRINTF   fprintf

#ifdef _DEBUG_TEST
#define _PRINT_VER( cd ) PRINTF( stdout,"\t%s 0x%x(%d)\n", #cd, (INT)cd, (INT)cd ) ;
#else
#define _PRINT_VER( cd ) 
#endif

#ifdef _DEBUG_TEST
#define _PRINT_ERRCD( cd ) PRINTF( stdout,"\t%s %s\n", #cd, _convert_ERROR( (ER)cd ) ) ;
#else
#define _PRINT_ERRCD( cd ) 
#endif

#define _CHECK_ASSERT_ERCD( ercd, E ) { if ( !( MERCD( ercd ) == E ) ) \
	{ _test_assert_ercd( #ercd, #E ) ; _PRINT_ERRCD( ercd ) ; } }

#define _CHECK_ASSERT_E_OK( ercd ) _CHECK_ASSERT_ERCD( ercd, E_OK )

#ifdef _ASSERT_E_PAR
#define _CHECK_ASSERT_E_PAR( ercd ) _CHECK_ASSERT_ERCD( ercd, E_PAR )
#else
#define _CHECK_ASSERT_E_PAR( ercd ) { if ( !( MERCD( ercd ) == E_PAR ) ) \
	_PRINT_VER( ercd ) ; }
#endif

#ifdef _ASSERT_E_RSATR
#define _CHECK_ASSERT_E_RSATR( ercd ) _CHECK_ASSERT_ERCD( ercd, E_RSATR )
#else
#define _CHECK_ASSERT_E_RSATR( ercd ) { if ( !( MERCD( ercd ) == E_RSATR ) ) \
	_PRINT_VER( ercd ) ; }
#endif

#define _CHECK_ASSERT_E_ID( ercd ) _CHECK_ASSERT_ERCD( ercd, E_ID )
#define _CHECK_ASSERT_E_NOID( ercd ) _CHECK_ASSERT_ERCD( ercd, E_NOID )
#define _CHECK_ASSERT_E_OBJ( ercd ) _CHECK_ASSERT_ERCD( ercd, E_OBJ )
#define _CHECK_ASSERT_E_NOEXS( ercd ) _CHECK_ASSERT_ERCD( ercd, E_NOEXS )
#define _CHECK_ASSERT_E_ILUSE( ercd ) _CHECK_ASSERT_ERCD( ercd, E_ILUSE )
#define _CHECK_ASSERT_E_NOMEM( ercd ) _CHECK_ASSERT_ERCD( ercd, E_NOMEM )
#define _CHECK_ASSERT_E_QOVR( ercd ) _CHECK_ASSERT_ERCD( ercd, E_QOVR )

#define _CHECK_ASSERT_E_TMOUT( ercd ) _CHECK_ASSERT_ERCD( ercd, E_TMOUT )
#define _CHECK_ASSERT_E_DLT( ercd ) _CHECK_ASSERT_ERCD( ercd, E_DLT )
#define _CHECK_ASSERT_E_RLWAI( ercd ) _CHECK_ASSERT_ERCD( ercd, E_RLWAI )
#define _CHECK_ASSERT_E_CTX( ercd ) _CHECK_ASSERT_ERCD( ercd, E_CTX )
#define _CHECK_ASSERT_E_RSFN( ercd ) _CHECK_ASSERT_ERCD( ercd, E_RSFN )
#define _CHECK_ASSERT_E_MACV( ercd ) _CHECK_ASSERT_ERCD( ercd, E_MACV )
#define _CHECK_ASSERT_E_NOSPT( ercd ) _CHECK_ASSERT_ERCD( ercd, E_NOSPT )


char* _convert_ERROR( ER ercd )
{
	switch(ercd) {
	case E_OK:
		return("E_OK");
	case E_SYS:
		return("E_SYS");
	case E_NOSPT:
		return("E_NOSPT");
	case E_RSFN:
		return("E_RSFN");
	case E_RSATR:
		return("E_RSATR");
	case E_PAR:
		return("E_PAR");
	case E_ID:
		return("E_ID");
	case E_CTX:
		return("E_CTX");
	case E_MACV:
		return("E_MACV");
	case E_OACV:
		return("E_OACV");
	case E_ILUSE:
		return("E_ILUSE");
	case E_NOMEM:
		return("E_NOMEM");
	case E_NOID:
		return("E_NOID");
	case E_OBJ:
		return("E_OBJ");
	case E_NOEXS:
		return("E_NOEXS");
	case E_QOVR:
		return("E_QOVR");
	case E_RLWAI:
		return("E_RLWAI");
	case E_TMOUT:
		return("E_TMOUT");
	case E_DLT:
		return("E_DLT");
	case E_CLS:
		return("E_CLS");
	case E_WBLK:
		return("E_WBLK");
	case E_BOVR:
		return("E_BOVR");
	}
	return NULL;
}


inline void _test_check_step_( int nStep )
{
	if ( nStep != nTestCurrentStep + 1 ) {
		PRINTF( stdout,"**** Illegal Sequence ( %d -> %d )****\n",
			nTestCurrentStep, nStep ) ;
	}
	nTestCurrentStep = nStep ;
	if(nStep==_LAST_STEP){
	    PRINTF(stdout,"---Reached Last Step---\n");
	}
}

inline void _test_check_step( int nStep )
{
#ifdef _DEBUG_TEST
	PRINTF( stdout,"Step%d\n", nStep ) ;
#endif
	_test_check_step_( nStep ) ;
}

void _test_assert( char* szCond )
{
	PRINTF( stdout,"**** Assert! Step(%d) : %s ****\n", nTestCurrentStep, szCond ) ;
	bTestAssertOccured = TRUE ;
}

void _test_assert_ercd( char *ercd, char* szCond )
{
	PRINTF( stdout,"**** Assert! Step(%d) : MERCD( %s ) == %s ****\n", nTestCurrentStep, ercd, szCond ) ;
	bTestAssertOccured = TRUE ;
}


#define PREPARE_SW_DELAY( n ) _test_prepare_sw_delay( n ) ;
#define SW_DELAY() _test_sw_delay() ;

int ud4SwDly ;

void _test_sw_delay()
{
	volatile int ud ;
	for ( ud = 0 ; ud < ud4SwDly ; ud++ ) ;
}


void _test_prepare_sw_delay( int nDelay )
{
	for ( ud4SwDly = 1 ; ud4SwDly ; ud4SwDly *= 2 ) {
		SYSTIM t1, t2 ;
		get_tim( &t1 ) ;
		_test_sw_delay() ;
		get_tim( &t2 ) ;
		t2 -= t1 ;
		if ( t2 > nDelay ) break ;
	}
}

VP _read_sp()
{
	__asm("mov sp, r0");
}

BOOL is_bufmgr_buffer(VP ptr)
{
extern VP __kernel_bufmgr_buffer[];
extern const SIZE __kernel_bufmgr_buffer_size;

return(ptr >= __kernel_bufmgr_buffer && ptr <= & __kernel_bufmgr_buffer[__kernel_bufmgr_buffer_size]) ;
}

#endif /* _NEED_TEST_ROUTINES*/
#endif /*test_com*/

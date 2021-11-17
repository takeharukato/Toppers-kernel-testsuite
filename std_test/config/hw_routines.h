/* TOPPERS�J�[�l���e�X�g�X�C�[�g
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 */

/*-------�n�[�h�E�F�A�ˑ��̃��[�`���̒�`------*/

#ifdef SH7727
//----SPC04
/*---timer interrupt ---*/
#define IPRA  (volatile short *)0xfffffee2
#define  TSTR (volatile char *) 0xfffffe92

#define TCOR1   (volatile int *) 0xfffffea0
#define TCNT1  (volatile int *)0xfffffea4
#define TCR1 (volatile short *) 0xfffffea8
#define TIMER1_START_BIT 0x01
#define PRI_BIT1 0x08

#define TCOR2   (volatile int *) 0xfffffeac
#define TCNT2  (volatile int *)0xfffffeb0
#define TCR2 (volatile short *) 0xfffffeb4
#define TIMER2_START_BIT 0x02
#define PRI_BIT2 0x04

#define TIMER_PRI   0x01
#define UNIE_BIT 0x05
#define TPSC0_BIT   0x0

#define TIMER_COUNT 0x01
#define TIMER_10MSEC  1600000

#define RAISE_INTERRUPT  raise_interrupt
#define CLEAR_INTERRUPT clear_timer
#define RAISE_INTERRUPT1_10ms test_raise_interrupt_10ms

#define RAISE_CPU_EXCEPTION1	   load_error
#define RAISE_CPU_EXCEPTION2	   load_error2

inline void start_timer(int timer_count)
{    int i=0;
    
#if INHNO_1 == INHNO_TMU1
    *TCR1=(1 << UNIE_BIT | 1 << TPSC0_BIT);
    *TCNT1=timer_count;
    *TCOR1=timer_count;
    *IPRA|=(TIMER_PRI << PRI_BIT1);
    *TSTR|=(1 << TIMER1_START_BIT);    
#else
    *TCR2=(1 << UNIE_BIT | 1 << TPSC0_BIT);
    *TCNT2=timer_count;
    *TCOR2=timer_count;
    *IPRA|=(TIMER_PRI << PRI_BIT2);
    *TSTR|=(1 << TIMER2_START_BIT);    
#endif
}

inline void clear_timer()
{
#if INHNO_1 == INHNO_TMU1
    *TSTR&=~(1 << TIMER1_START_BIT);
    *TCR1=0x0;
#else
    *TSTR&=~(1 << TIMER2_START_BIT);
    *TCR2=0x0;
#endif
}

inline void load_error()
{
    int p=1;
    
    __raise_exception((int *)p);
}


static int __raise_exception(int *p)
{
    *((int *)p);
}

static int __raise_exception2(int *p)
{
    *((int *)p);
}
inline void load_error2()
{
    int p=1;
    
    __raise_exception2((int *)p);
}


void _test_raise_exception_back()
{
	unsigned short *p;

	p = (unsigned short *)__raise_exception;
	*p = 0x0009;
}

void _test_raise_exception_back2()
{
	unsigned short *p;

	p = (unsigned short *)__raise_exception2;
	*p = 0x0009;
}

inline void raise_interrupt()
{
    start_timer(0x01);
    
}

inline void test_raise_interrupt_10ms()
{
    start_timer(TIMER_10MSEC);

}
/*-----------------------------*/
#endif

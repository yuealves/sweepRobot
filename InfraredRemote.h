#ifndef __InfraredRemote__H__
#define __InfraredRemote__H__

#include <Arduino.h>

#define IR_IN 4 //�������

extern void timer1_init(void);	//��ʱ����ʼ������
extern char logic_value();//�ж��߼�ֵ��0���͡�1���Ӻ���
extern void pulse_deal();//���յ�ַ������������庯��
extern void remote_decode(void);
extern void remote_deal(void);//ִ������������

extern unsigned int ir_code;// �û�����ֵ
extern unsigned int adrL_code;//������
extern unsigned int adrH_code;//�����뷴��

#endif

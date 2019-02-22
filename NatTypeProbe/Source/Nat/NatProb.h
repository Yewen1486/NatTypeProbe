/* *
 * @program: NatTypeProb
 *
 * @description: ����Nat����̽��͹����˿ڻ�ȡ������ڲ��ܷ��������Ļ�����ʹ�ã��ӿڷ��ػ�ʧ��
 *               ʹ�÷�����
 *               1������ Init() �������г�ʼ����
 *               2������ GetNatType() ����̽��Nat���ͣ�����Ҫ���������ν�������Ϊ��ʱ���������һ�Σ�
 *               3������ GetNatIpAndPort() ������ȡ����Ip�ʹ�͸�˿ڣ�������Ҫ�ɵ��ö�Σ�
 * @author: 909845
 *
 * @create: 2019-02-22 10:28
***/

#ifndef NATTYPEPROB_NATPROB_H
#define NATTYPEPROB_NATPROB_H

#include <string>
#include "Stun/p2p_api.h"
#include <map>

using namespace std;

class CNatProb
{
public:
    /*
     * ����:  Nat̽���ʼ��
     * ����:
     *       @strNatServerAddr      -- Nat��������ַ����ΪIp����������������Ϊ����������Nat������
     *       @uNatServerDefaultPort -- Nat������ʶ˿ڣ�Ĭ��3478
     */
    bool Init(const string& strNatServerAddr, const UInt16 uNatServerDefaultPort = STUN_PORT);


    /*
     * ����:  Nat����̽�⣬�ӿں�ʱ1-2s���ؽ�����ɵ������߳�̽�⣬��������ҵ���߳�
     * ����:  @port                       ̽��ʹ�õĶ˿ڶ�port, port+1��
     *                                   ��0��ʹ������˿ڣ����˿ڳ�ͻ���Զ��滻�˿ڳ��ԣ������������10��
     *                                   ��0��ʹ��ָ���ˣ����˿ڳ�ͻֱ��ʧ��
     * ����:  NatType Ϊ
     *       StunTypeOpen                ��ʾ������ڹ��������ж�����Ip��ַ����ֱ��ʹ��
     *       StunTypeConeNat             Բ׶��                        ��ʹ��
     *       StunTypeRestrictedNat       IP������                      ��ʹ��
     *       StunTypePortRestrictedNat   �˿�������                     ��ʹ��
     *       StunTypeSymNat              �Գ���                        ���������ת����˿�Ԥ��ſ���ʹ��
     *       ����                         ��Ϊ���ɴ�͸��͸ʧ��
     */
    NatType GetNatType(UInt16 port = 0);

    /*
     * ����:  ��ȡ����IP�Ͷ˿ڣ��ӿڷ���300ms -1s���ɵ������߳�̽�⣬��������ҵ���߳�
     * ����:
     *       @strLocalIp                 ����Ip��ַ������Ϊ0.0.0.0
     *       @uLocalPort                 ��Ҫ��͸�ı��ض˿ڣ��˿ڳ�ͻֱ�ӷ���ʧ��
     *       @strPublicIp                ����Ip��Ӧ�Ĺ���IP
     *       @uPublicPort                ���ض˿ڶ�Ӧ�Ĺ����˿�
     * ����:
     *       true                        �ɹ�
     *       false                       ʧ��
     */
    bool GetNatIpAndPort(const string &strLocalIp, const UInt16& uLocalPort, string& strPublicIp, UInt16& uPublicPort);

    /*
     * ����ö��ֵ����Nat����
     */
    static string DescribeNatType(const NatType natType);

private:
    StunAddress4 m_NatServerAddr = {0};//����Nat����������������

    static const map<NatType, string>  m_mpNatTypeDesc;
};


#endif //NATTYPEPROB_NATPROB_H

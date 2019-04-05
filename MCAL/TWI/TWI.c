/*
 * TWI.c
 *
 *  Created on: Apr 5, 2019
 *      Author: Muhammad.Elzeiny
 */
typedef enum
{
	BusError=0,

	Master_Start_Condition = 0x08,
	Master_RepeatedStart_Condition = 0x10,

	MasterTx_SlaWbTx_AckRx = 0x18,
	MasterTx_SlaWbTx_NotAckRx =0x20,
	MasterTx_DataTx_AckRx=0x28,
	MasterTx_DataTx_NotAckRx=0x30,

	Master_ArbitrationLost=0x38,

	MasterRx_SlaRbTx_AckRx = 0x40,
	MasterRx_SlaRbTx_NotAckRx =0x48,
	MasterRx_DataRx_AckTx=0x50,
	MasterRx_DataRx_NotAckTx=0x58,

	SlaveRx_SlaWbRx_AckTx = 0x60,
	SlaveRx_ArbitrationLost_SlaWbRx_AckTx = 0x68,
	SlaveRx_BroadcastAddrRx_AckTx = 0x70,
	SlaveRx_ArbitrationLost_BroadcastAddrRx_AckTx = 0x78,

	SlaveRx_PrevSlaWbRx_AckTx = 0x80,
	SlaveRx_PrevArbitrationLost_SlaWbRx_AckTx = 0x88,
	SlaveRx_PrevBroadcastAddrRx_AckTx = 0x90,
	SlaveRx_PrevArbitrationLost_BroadcastAddrRx_AckTx = 0x98,

	SlaveRx_StopCondition_Or_RepeatedStartCondition = 0xA0,

	SlaveTx_SlaRbRx_AckTx = 0xA8,
	SlaveTx_ArbitrationLost_SlaRbRx_AckTx = 0xB0,

	SlaveTx_DataTx_AckRx = 0xB8,
	SlaveTx_DataTx_NotAckRx = 0xC0,
	SlaveTx_LastDataTx_AckRx = 0xC8,

	NoRelevantState = 0xF8

}TWI_status_t;

#define TWI_PRESCALER_clr_msk		  0x11111100
#define TWI_PRESCALER_1_msk           0x00000000
#define TWI_PRESCALER_4_msk           0x00000001
#define TWI_PRESCALER_16_msk          0x00000010
#define TWI_PRESCALER_64_msk          0x00000011

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TWI_reg.h"
#include "TWI_cfg.h"
#include "TWI.h"

void TWI_init(void)
{
	/*init cfg*/
	TWBR = TWI_BITRATE_TWBR_VAL;

	TWSR &= TWI_PRESCALER_clr_msk;
	TWSR |= TWI_PRESCALER_SELECTOR_msk;

	TWAR = TWI_NODE_ADDRESS<<1;
	ASSIGN_BIT(TWAR,0,TWI_BROADCAST_EN);

	/*enable TWI*/
	SET_BIT(TWCR,2);
}

void TWI_DISCONNECT_NODE(void)
{
	CLR_BIT(TWCR,6);
}
void TWI_CONNECT_NODE(void)
{
	SET_BIT(TWCR,6);
}
void TWI_START_CONDITION(void)
{
	SET_BIT(TWCR,5);
}
void TWI_STOP_CONDITION(void)
{
	SET_BIT(TWCR,4);
}
void TWI_enInterrupt(void)
{
	SET_BIT(TWCR,0);
}

void TWI_diInterrupt(void)
{
	CLR_BIT(TWCR,0);
}
TWI_sendMsg(u8 SlaveAddress,u8 TxMsg[],u8 SizeCpy)
{


}
TWI_ReceiveMsg(u8 SlaveAddress,u8 RxMsg[],u8* SizePtr)
{


}
void __vector_19(void) __attribute__((signal,used))
		void __vector_19(void)
{
	TWI_status_t CurrentStatus = TWSR & 0b11111100;
	switch(CurrentStatus)
	{
	case BusError :

		break;
	case Master_RepeatedStart_Condition :

		break;
	case Master_Start_Condition :
		/*TWDR*/
		break;

	case MasterTx_SlaWbTx_NotAckRx :

		break;
	case MasterTx_SlaWbTx_AckRx :

		break;

	case MasterTx_DataTx_NotAckRx :

		break;
	case MasterTx_DataTx_AckRx :

		break;

	case Master_ArbitrationLost :

		break;
	case MasterRx_SlaRbTx_AckRx :

		break;
	case MasterRx_SlaRbTx_NotAckRx :

		break;
	case MasterRx_DataRx_AckTx :
		break;
	case MasterRx_DataRx_NotAckTx :

		break;
	case SlaveRx_SlaWbRx_AckTx :

		break;
	case SlaveRx_ArbitrationLost_SlaWbRx_AckTx:

		break;
	case SlaveRx_BroadcastAddrRx_AckTx:

		break;
	case SlaveRx_ArbitrationLost_BroadcastAddrRx_AckTx:

		break;
	case SlaveRx_PrevSlaWbRx_AckTx:

		break;
	case SlaveRx_PrevArbitrationLost_SlaWbRx_AckTx:

		break;
	case SlaveRx_PrevBroadcastAddrRx_AckTx:

		break;
	case SlaveRx_PrevArbitrationLost_BroadcastAddrRx_AckTx:

		break;
	case SlaveRx_StopCondition_Or_RepeatedStartCondition:

		break;
	case SlaveTx_SlaRbRx_AckTx:

		break;
	case SlaveTx_ArbitrationLost_SlaRbRx_AckTx:

		break;
	case SlaveTx_DataTx_AckRx:

		break;
	case SlaveTx_DataTx_NotAckRx:

		break;
	case SlaveTx_LastDataTx_AckRx:

		break;
	case NoRelevantState:
		break;
	default:
		break;

	}

	/*interrupt flag should be cleared
	 * by writing one to it*/
	 SET_BIT(TWCR,7);
}


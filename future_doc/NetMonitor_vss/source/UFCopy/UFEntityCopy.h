/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file UFEntityCopy.h
///@brief实现了UFEntity之间互相复制的程序
///@history 
///20051210	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef UFEntityCopy_H
#define UFEntityCopy_H

#ifndef CopyUserFunctionRightEntity
#define CopyUserFunctionRightEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->FunctionCode=(source)->FunctionCode;	\

#endif
#ifndef CopyAliasDefineEntity
#define CopyAliasDefineEntity(target,source)	\
			(target)->StartPos=(source)->StartPos;	\
			(target)->Alias=(source)->Alias;	\
			(target)->OriginalText=(source)->OriginalText;	\

#endif
#ifndef CopyClearingTradingPartEntity
#define CopyClearingTradingPartEntity(target,source)	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopyTmdbAccomplishEntity
#define CopyTmdbAccomplishEntity(target,source)	\
			(target)->CommPhaseNo=(source)->CommPhaseNo;	\
			(target)->SequenceNo=(source)->SequenceNo;	\

#endif
#ifndef CopyInputOrderActionV1Entity
#define CopyInputOrderActionV1Entity(target,source)	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->OrderLocalID=(source)->OrderLocalID;	\
			(target)->ActionFlag=(source)->ActionFlag;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->LimitPrice=(source)->LimitPrice;	\
			(target)->VolumeChange=(source)->VolumeChange;	\
			(target)->ActionLocalID=(source)->ActionLocalID;	\

#endif
#ifndef CopyInputOrderActionV2Entity
#define CopyInputOrderActionV2Entity(target,source)	\
			CopyInputOrderActionV1Entity(target,source);	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\

#endif
#ifndef CopyInputOrderActionEntity
#define CopyInputOrderActionEntity(target,source)	\
			CopyInputOrderActionV2Entity(target,source);	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyOrderActionEntity
#define CopyOrderActionEntity(target,source)	\
			CopyInputOrderActionV2Entity(target,source);	\
			(target)->ActionSource=(source)->ActionSource;	\
			(target)->Tradable=(source)->Tradable;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyInputQuoteActionV1Entity
#define CopyInputQuoteActionV1Entity(target,source)	\
			(target)->QuoteSysID=(source)->QuoteSysID;	\
			(target)->QuoteLocalID=(source)->QuoteLocalID;	\
			(target)->ActionFlag=(source)->ActionFlag;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ActionLocalID=(source)->ActionLocalID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\

#endif
#ifndef CopyInputQuoteActionEntity
#define CopyInputQuoteActionEntity(target,source)	\
			CopyInputQuoteActionV1Entity(target,source);	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyQuoteActionEntity
#define CopyQuoteActionEntity(target,source)	\
			CopyInputQuoteActionV1Entity(target,source);	\
			(target)->ActionSource=(source)->ActionSource;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyInputExecOrderActionV1Entity
#define CopyInputExecOrderActionV1Entity(target,source)	\
			(target)->ExecOrderSysID=(source)->ExecOrderSysID;	\
			(target)->ExecOrderLocalID=(source)->ExecOrderLocalID;	\
			(target)->ActionFlag=(source)->ActionFlag;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ActionLocalID=(source)->ActionLocalID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\

#endif
#ifndef CopyInputExecOrderActionEntity
#define CopyInputExecOrderActionEntity(target,source)	\
			CopyInputExecOrderActionV1Entity(target,source);	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyExecOrderActionEntity
#define CopyExecOrderActionEntity(target,source)	\
			CopyInputExecOrderActionV1Entity(target,source);	\
			(target)->ActionSource=(source)->ActionSource;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyInputAbandonExecOrderActionV1Entity
#define CopyInputAbandonExecOrderActionV1Entity(target,source)	\
			(target)->AbandonExecOrderSysID=(source)->AbandonExecOrderSysID;	\
			(target)->AbandonExecOrderLocalID=(source)->AbandonExecOrderLocalID;	\
			(target)->ActionFlag=(source)->ActionFlag;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ActionLocalID=(source)->ActionLocalID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\

#endif
#ifndef CopyInputAbandonExecOrderActionEntity
#define CopyInputAbandonExecOrderActionEntity(target,source)	\
			CopyInputAbandonExecOrderActionV1Entity(target,source);	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyAbandonExecOrderActionEntity
#define CopyAbandonExecOrderActionEntity(target,source)	\
			CopyInputAbandonExecOrderActionV1Entity(target,source);	\
			(target)->ActionSource=(source)->ActionSource;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyCurrentTimeEntity
#define CopyCurrentTimeEntity(target,source)	\
			(target)->CurrDate=(source)->CurrDate;	\
			(target)->CurrTime=(source)->CurrTime;	\
			(target)->CurrMillisec=(source)->CurrMillisec;	\

#endif
#ifndef CopyErrorTypeEntity
#define CopyErrorTypeEntity(target,source)	\
			(target)->ErrorID=(source)->ErrorID;	\
			(target)->ErrorMsg=(source)->ErrorMsg;	\

#endif
#ifndef CopyOperationDefineEntity
#define CopyOperationDefineEntity(target,source)	\
			(target)->OperationType=(source)->OperationType;	\
			(target)->OperationName=(source)->OperationName;	\

#endif
#ifndef CopyTradingDayRefEntity
#define CopyTradingDayRefEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\

#endif
#ifndef CopyExchangeStatusEntity
#define CopyExchangeStatusEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->ExchangeID=(source)->ExchangeID;	\
			(target)->ExchangeStatus=(source)->ExchangeStatus;	\

#endif
#ifndef CopyExchangeDataSyncStatusEntity
#define CopyExchangeDataSyncStatusEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->ExchangeID=(source)->ExchangeID;	\
			(target)->ExchangeDataSyncStatus=(source)->ExchangeDataSyncStatus;	\

#endif
#ifndef CopySettlementRefEntity
#define CopySettlementRefEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopySettlementGroupStatusEntity
#define CopySettlementGroupStatusEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->SettlementGroupStatus=(source)->SettlementGroupStatus;	\
			(target)->EnterTime=(source)->EnterTime;	\
			(target)->EnterDate=(source)->EnterDate;	\

#endif
#ifndef CopySGDataSyncStatusEntity
#define CopySGDataSyncStatusEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->SGDataSyncStatus=(source)->SGDataSyncStatus;	\

#endif
#ifndef CopyInstrumentStatusV1Entity
#define CopyInstrumentStatusV1Entity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->InstrumentStatus=(source)->InstrumentStatus;	\
			(target)->TradingSegmentSN=(source)->TradingSegmentSN;	\
			(target)->EnterTime=(source)->EnterTime;	\
			(target)->EnterReason=(source)->EnterReason;	\

#endif
#ifndef CopyInstrumentStatusEntity
#define CopyInstrumentStatusEntity(target,source)	\
			CopyInstrumentStatusV1Entity(target,source);	\
			(target)->EnterDate=(source)->EnterDate;	\

#endif
#ifndef CopyInstrumentStatusDetailEntity
#define CopyInstrumentStatusDetailEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyInstrumentStatusV1Entity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->EnterDate=(source)->EnterDate;	\

#endif
#ifndef CopySettlementGroupRefEntity
#define CopySettlementGroupRefEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\

#endif
#ifndef CopyExchangeEntity
#define CopyExchangeEntity(target,source)	\
			(target)->ExchangeID=(source)->ExchangeID;	\
			(target)->ExchangeName=(source)->ExchangeName;	\

#endif
#ifndef CopyExchangePropertyEntity
#define CopyExchangePropertyEntity(target,source)	\
			(target)->ExchangeID=(source)->ExchangeID;	\
			(target)->ExchangeLifePhase=(source)->ExchangeLifePhase;	\

#endif
#ifndef CopySettlementGroupEntity
#define CopySettlementGroupEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementGroupName=(source)->SettlementGroupName;	\
			(target)->ExchangeID=(source)->ExchangeID;	\
			(target)->Currency=(source)->Currency;	\

#endif
#ifndef CopySettlementGroupPropertyEntity
#define CopySettlementGroupPropertyEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementGroupLifePhase=(source)->SettlementGroupLifePhase;	\

#endif
#ifndef CopyProductGroupEntity
#define CopyProductGroupEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\
			(target)->ProductGroupName=(source)->ProductGroupName;	\
			(target)->CommodityID=(source)->CommodityID;	\

#endif
#ifndef CopyProductGroupPropertyEntity
#define CopyProductGroupPropertyEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\
			(target)->ProductGroupLifePhase=(source)->ProductGroupLifePhase;	\

#endif
#ifndef CopyProductEntity
#define CopyProductEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\
			(target)->ProductName=(source)->ProductName;	\
			(target)->ProductClass=(source)->ProductClass;	\

#endif
#ifndef CopyProductPropertyEntity
#define CopyProductPropertyEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ProductLifePhase=(source)->ProductLifePhase;	\
			(target)->TradingModel=(source)->TradingModel;	\
			(target)->OptionsLimitRatio=(source)->OptionsLimitRatio;	\
			(target)->OptionsMgRatio=(source)->OptionsMgRatio;	\
			(target)->SettlePriceSeconds=(source)->SettlePriceSeconds;	\

#endif
#ifndef CopyInstTradingPropertyEntity
#define CopyInstTradingPropertyEntity(target,source)	\
			(target)->MaxMarketOrderVolume=(source)->MaxMarketOrderVolume;	\
			(target)->MinMarketOrderVolume=(source)->MinMarketOrderVolume;	\
			(target)->MaxLimitOrderVolume=(source)->MaxLimitOrderVolume;	\
			(target)->MinLimitOrderVolume=(source)->MinLimitOrderVolume;	\
			(target)->PriceTick=(source)->PriceTick;	\
			(target)->AllowDelivPersonOpen=(source)->AllowDelivPersonOpen;	\

#endif
#ifndef CopyInstDynPropertyEntity
#define CopyInstDynPropertyEntity(target,source)	\
			(target)->CreateDate=(source)->CreateDate;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->ExpireDate=(source)->ExpireDate;	\
			(target)->StartDelivDate=(source)->StartDelivDate;	\
			(target)->EndDelivDate=(source)->EndDelivDate;	\
			(target)->BasisPrice=(source)->BasisPrice;	\

#endif
#ifndef CopyInstDynPropertyExprEntity
#define CopyInstDynPropertyExprEntity(target,source)	\
			(target)->CreateDateExpr=(source)->CreateDateExpr;	\
			(target)->OpenDateExpr=(source)->OpenDateExpr;	\
			(target)->ExpireDateExpr=(source)->ExpireDateExpr;	\
			(target)->StartDelivDateExpr=(source)->StartDelivDateExpr;	\
			(target)->EndDelivDateExpr=(source)->EndDelivDateExpr;	\
			(target)->BasisPriceType=(source)->BasisPriceType;	\

#endif
#ifndef CopyInstIDAndNameExprEntity
#define CopyInstIDAndNameExprEntity(target,source)	\
			(target)->InstrumentIDExpr=(source)->InstrumentIDExpr;	\
			(target)->InstrumentNameExpr=(source)->InstrumentNameExpr;	\

#endif
#ifndef CopyInstBasicPropertyEntity
#define CopyInstBasicPropertyEntity(target,source)	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\
			(target)->UnderlyingInstrID=(source)->UnderlyingInstrID;	\
			(target)->ProductClass=(source)->ProductClass;	\
			(target)->PositionType=(source)->PositionType;	\
			(target)->StrikePrice=(source)->StrikePrice;	\
			(target)->OptionsType=(source)->OptionsType;	\
			(target)->VolumeMultiple=(source)->VolumeMultiple;	\
			(target)->UnderlyingMultiple=(source)->UnderlyingMultiple;	\

#endif
#ifndef CopyInstCreateRuleEntity
#define CopyInstCreateRuleEntity(target,source)	\
			(target)->AdvanceMonthArray=(source)->AdvanceMonthArray;	\
			(target)->SpecialCreateRule=(source)->SpecialCreateRule;	\
			(target)->OptionsUpperInstCreated=(source)->OptionsUpperInstCreated;	\
			(target)->OptionsLowerInstCreated=(source)->OptionsLowerInstCreated;	\
			(target)->OptionsUpperInstMaintain=(source)->OptionsUpperInstMaintain;	\
			(target)->OptionsLowerInstMaintain=(source)->OptionsLowerInstMaintain;	\
			(target)->ApproachRule=(source)->ApproachRule;	\

#endif
#ifndef CopyInstrumentEntity
#define CopyInstrumentEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyInstBasicPropertyEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->InstrumentName=(source)->InstrumentName;	\
			(target)->DeliveryYear=(source)->DeliveryYear;	\
			(target)->DeliveryMonth=(source)->DeliveryMonth;	\
			(target)->AdvanceMonth=(source)->AdvanceMonth;	\

#endif
#ifndef CopyTradingInstrumentV1Entity
#define CopyTradingInstrumentV1Entity(target,source)	\
			CopyInstrumentEntity(target,source);	\
			(target)->IsTrading=(source)->IsTrading;	\

#endif
#ifndef CopyTradingInstrumentEntity
#define CopyTradingInstrumentEntity(target,source)	\
			CopyTradingInstrumentV1Entity(target,source);	\
			(target)->CurrencyID=(source)->CurrencyID;	\

#endif
#ifndef CopyInstrumentPropertyEntity
#define CopyInstrumentPropertyEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyInstDynPropertyEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->InstLifePhase=(source)->InstLifePhase;	\

#endif
#ifndef CopyInstrumentPropertyForSyncEntity
#define CopyInstrumentPropertyForSyncEntity(target,source)	\
			CopyCurrInstrumentPropertyEntity(target,source);	\
			(target)->IsFirstTradingDay=(source)->IsFirstTradingDay;	\

#endif
#ifndef CopyInstrumentAttrEntity
#define CopyInstrumentAttrEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyInstTradingPropertyEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->PeriodID=(source)->PeriodID;	\
			(target)->PeriodName=(source)->PeriodName;	\
			(target)->StartDateExpr=(source)->StartDateExpr;	\

#endif
#ifndef CopyCombinationLegEntity
#define CopyCombinationLegEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->CombInstrumentID=(source)->CombInstrumentID;	\
			(target)->LegID=(source)->LegID;	\
			(target)->LegInstrumentID=(source)->LegInstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->LegMultiple=(source)->LegMultiple;	\
			(target)->ImplyLevel=(source)->ImplyLevel;	\

#endif
#ifndef CopyParticipantEntity
#define CopyParticipantEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->MemberType=(source)->MemberType;	\
			(target)->IsActive=(source)->IsActive;	\

#endif
#ifndef CopyUserV1Entity
#define CopyUserV1Entity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserType=(source)->UserType;	\
			(target)->Password=(source)->Password;	\
			(target)->IsActive=(source)->IsActive;	\

#endif
#ifndef CopyUserEntity
#define CopyUserEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserType=(source)->UserType;	\
			(target)->Password=(source)->Password;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->IsDirectConnForbidden=(source)->IsDirectConnForbidden;	\

#endif
#ifndef CopyUserIPEntity
#define CopyUserIPEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->IPMask=(source)->IPMask;	\

#endif
#ifndef CopyUpdateAllInstrumentStatusEntity
#define CopyUpdateAllInstrumentStatusEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentStatus=(source)->InstrumentStatus;	\

#endif
#ifndef CopyDbmtRefEntity
#define CopyDbmtRefEntity(target,source)	\
			(target)->DbmtTopicID=(source)->DbmtTopicID;	\
			(target)->DbmtSequenceID=(source)->DbmtSequenceID;	\

#endif
#ifndef CopyClientEntity
#define CopyClientEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->IsActive=(source)->IsActive;	\

#endif
#ifndef CopyDbmtAccountDepositEntity
#define CopyDbmtAccountDepositEntity(target,source)	\
			CopyAccountDepositEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtUpdateAllInstrumentStatusEntity
#define CopyDbmtUpdateAllInstrumentStatusEntity(target,source)	\
			CopyUpdateAllInstrumentStatusEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtClientEntity
#define CopyDbmtClientEntity(target,source)	\
			CopyClientEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtPartClientEntity
#define CopyDbmtPartClientEntity(target,source)	\
			CopyPartClientEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrPartPosiLimitDetailEntity
#define CopyDbmtCurrPartPosiLimitDetailEntity(target,source)	\
			CopyCurrPartPosiLimitDetailEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrClientPosiLimitDetailEntity
#define CopyDbmtCurrClientPosiLimitDetailEntity(target,source)	\
			CopyCurrClientPosiLimitDetailEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrSpecialPosiLimitDetailEntity
#define CopyDbmtCurrSpecialPosiLimitDetailEntity(target,source)	\
			CopyCurrSpecialPosiLimitDetailEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtHedgeDetailEntity
#define CopyDbmtHedgeDetailEntity(target,source)	\
			CopyHedgeDetailEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrHedgeEntity
#define CopyDbmtCurrHedgeEntity(target,source)	\
			CopyCurrHedgeEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtUserEntity
#define CopyDbmtUserEntity(target,source)	\
			CopyUserV1Entity(target,source);	\
			CopyDbmtRefEntity(target,source);	\
			(target)->IsDirectConnForbidden=(source)->IsDirectConnForbidden;	\

#endif
#ifndef CopyDbmtPartProductRightEntity
#define CopyDbmtPartProductRightEntity(target,source)	\
			CopyPartProductRightEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtClientProductRightEntity
#define CopyDbmtClientProductRightEntity(target,source)	\
			CopyClientProductRightEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtPartInstrumentRightEntity
#define CopyDbmtPartInstrumentRightEntity(target,source)	\
			CopyPartInstrumentRightEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtClientInstrumentRightEntity
#define CopyDbmtClientInstrumentRightEntity(target,source)	\
			CopyClientInstrumentRightEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtPartClientProductRightEntity
#define CopyDbmtPartClientProductRightEntity(target,source)	\
			CopyPartClientProductRightEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtPartClientInstrumentRightEntity
#define CopyDbmtPartClientInstrumentRightEntity(target,source)	\
			CopyPartClientInstrumentRightEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrMarginRateDetailEntity
#define CopyDbmtCurrMarginRateDetailEntity(target,source)	\
			CopyCurrMarginRateDetailEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtMarketDataEntity
#define CopyDbmtMarketDataEntity(target,source)	\
			CopyMarketDataEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtUserIPEntity
#define CopyDbmtUserIPEntity(target,source)	\
			CopyUserIPEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrPriceBandingEntity
#define CopyDbmtCurrPriceBandingEntity(target,source)	\
			CopyCurrPriceBandingEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtClockDeltaEntity
#define CopyDbmtClockDeltaEntity(target,source)	\
			CopyClockDeltaEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDbmtCurrTradingSegmentAttrEntity
#define CopyDbmtCurrTradingSegmentAttrEntity(target,source)	\
			CopyCurrTradingSegmentAttrEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyDepartmentBaseEntity
#define CopyDepartmentBaseEntity(target,source)	\
			(target)->DepartmentID=(source)->DepartmentID;	\
			(target)->DepartmentName=(source)->DepartmentName;	\

#endif
#ifndef CopyMarketDataProviderBaseEntity
#define CopyMarketDataProviderBaseEntity(target,source)	\
			(target)->MarketDataProviderID=(source)->MarketDataProviderID;	\
			(target)->MarketDataProviderName=(source)->MarketDataProviderName;	\
			(target)->MarketDataProviderShortName=(source)->MarketDataProviderShortName;	\

#endif
#ifndef CopyClientBaseEntity
#define CopyClientBaseEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->IsActive=(source)->IsActive;	\

#endif
#ifndef CopyClientPropertyEntity
#define CopyClientPropertyEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRole=(source)->TradingRole;	\

#endif
#ifndef CopyPartClientEntity
#define CopyPartClientEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopySystemUserEntity
#define CopySystemUserEntity(target,source)	\
			(target)->SystemUserID=(source)->SystemUserID;	\
			(target)->SystemUserName=(source)->SystemUserName;	\
			(target)->SystemUserType=(source)->SystemUserType;	\
			(target)->BelongOrgID=(source)->BelongOrgID;	\
			(target)->IsActive=(source)->IsActive;	\

#endif
#ifndef CopyAccountEntity
#define CopyAccountEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->Currency=(source)->Currency;	\

#endif
#ifndef CopyMarketEntity
#define CopyMarketEntity(target,source)	\
			(target)->MarketID=(source)->MarketID;	\
			(target)->MarketName=(source)->MarketName;	\

#endif
#ifndef CopyMarketProductEntity
#define CopyMarketProductEntity(target,source)	\
			(target)->MarketID=(source)->MarketID;	\
			(target)->ProductID=(source)->ProductID;	\

#endif
#ifndef CopyMarketProductGroupEntity
#define CopyMarketProductGroupEntity(target,source)	\
			(target)->MarketID=(source)->MarketID;	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\

#endif
#ifndef CopyMarketDataTopicEntity
#define CopyMarketDataTopicEntity(target,source)	\
			(target)->TopicID=(source)->TopicID;	\
			(target)->TopicName=(source)->TopicName;	\
			(target)->MarketID=(source)->MarketID;	\
			(target)->SnapShotFeq=(source)->SnapShotFeq;	\
			(target)->MarketDataDepth=(source)->MarketDataDepth;	\
			(target)->DelaySeconds=(source)->DelaySeconds;	\
			(target)->MarketDataMode=(source)->MarketDataMode;	\

#endif
#ifndef CopyPartTopicSubscribeEntity
#define CopyPartTopicSubscribeEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantType=(source)->ParticipantType;	\
			(target)->TopicID=(source)->TopicID;	\

#endif
#ifndef CopyPartRoleAccountEntity
#define CopyPartRoleAccountEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->AccountID=(source)->AccountID;	\

#endif
#ifndef CopyPartProductRoleEntity
#define CopyPartProductRoleEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->TradingRole=(source)->TradingRole;	\

#endif
#ifndef CopyPartProductRightEntity
#define CopyPartProductRightEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRight=(source)->TradingRight;	\

#endif
#ifndef CopyPartInstrumentRightEntity
#define CopyPartInstrumentRightEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRight=(source)->TradingRight;	\

#endif
#ifndef CopyClientProductRightEntity
#define CopyClientProductRightEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRight=(source)->TradingRight;	\

#endif
#ifndef CopyClientInstrumentRightEntity
#define CopyClientInstrumentRightEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRight=(source)->TradingRight;	\

#endif
#ifndef CopyPartClientProductRightEntity
#define CopyPartClientProductRightEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRight=(source)->TradingRight;	\

#endif
#ifndef CopyPartClientInstrumentRightEntity
#define CopyPartClientInstrumentRightEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRight=(source)->TradingRight;	\

#endif
#ifndef CopyUniPressureEntity
#define CopyUniPressureEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->UpperPressureStartTime=(source)->UpperPressureStartTime;	\
			(target)->LowerPressureStartTime=(source)->LowerPressureStartTime;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyPriceBindingRuleEntity
#define CopyPriceBindingRuleEntity(target,source)	\
			(target)->PriceLimitType=(source)->PriceLimitType;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->RoundingMode=(source)->RoundingMode;	\
			(target)->UpperValue=(source)->UpperValue;	\
			(target)->LowerValue=(source)->LowerValue;	\

#endif
#ifndef CopyCurrInstrumentPropertyEntity
#define CopyCurrInstrumentPropertyEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyInstDynPropertyEntity(target,source);	\
			CopyInstTradingPropertyEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->InstLifePhase=(source)->InstLifePhase;	\

#endif
#ifndef CopyCurrPriceBandingEntity
#define CopyCurrPriceBandingEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyPriceBindingRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->TradingSegmentSN=(source)->TradingSegmentSN;	\

#endif
#ifndef CopyCurrMarginRateEntity
#define CopyCurrMarginRateEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyMarginCalcAlgoRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopyCurrMarginRateDetailEntity
#define CopyCurrMarginRateDetailEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyMarginRateRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopyPartPosiLimitCalcAlgorRefEntity
#define CopyPartPosiLimitCalcAlgorRefEntity(target,source)	\
			(target)->PartPosiLimitCalcID=(source)->PartPosiLimitCalcID;	\

#endif
#ifndef CopyPosiLimitRuleEntity
#define CopyPosiLimitRuleEntity(target,source)	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\

#endif
#ifndef CopyCurrPartPosiLimitEntity
#define CopyCurrPartPosiLimitEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyPartPosiLimitCalcAlgorRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopyCurrPartPosiLimitDetailEntity
#define CopyCurrPartPosiLimitDetailEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyPosiLimitRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\

#endif
#ifndef CopyClientPosiLimitCalcAlgoRefEntity
#define CopyClientPosiLimitCalcAlgoRefEntity(target,source)	\
			(target)->ClientPosiLimitCalcID=(source)->ClientPosiLimitCalcID;	\

#endif
#ifndef CopyCurrClientPosiLimitEntity
#define CopyCurrClientPosiLimitEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyClientPosiLimitCalcAlgoRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopyCurrClientPosiLimitDetailEntity
#define CopyCurrClientPosiLimitDetailEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyPosiLimitRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientType=(source)->ClientType;	\

#endif
#ifndef CopyCurrSpecialPosiLimitEntity
#define CopyCurrSpecialPosiLimitEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyClientPosiLimitCalcAlgoRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\

#endif
#ifndef CopyCurrSpecialPosiLimitDetailEntity
#define CopyCurrSpecialPosiLimitDetailEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyPosiLimitRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\

#endif
#ifndef CopyHedgeRuleEntity
#define CopyHedgeRuleEntity(target,source)	\
			(target)->HedgeUsageType=(source)->HedgeUsageType;	\

#endif
#ifndef CopyCurrHedgeRuleEntity
#define CopyCurrHedgeRuleEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyHedgeRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->HedgeCloseTodayType=(source)->HedgeCloseTodayType;	\

#endif
#ifndef CopyTradingSegmentRuleV1Entity
#define CopyTradingSegmentRuleV1Entity(target,source)	\
			(target)->TradingSegmentSN=(source)->TradingSegmentSN;	\
			(target)->TradingSegmentName=(source)->TradingSegmentName;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->InstrumentStatus=(source)->InstrumentStatus;	\

#endif
#ifndef CopyTradingSegmentRuleEntity
#define CopyTradingSegmentRuleEntity(target,source)	\
			CopyTradingSegmentRuleV1Entity(target,source);	\
			(target)->AdvanceDays=(source)->AdvanceDays;	\

#endif
#ifndef CopyCurrTradingSegmentAttrEntity
#define CopyCurrTradingSegmentAttrEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyTradingSegmentRuleV1Entity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->AdvanceDays=(source)->AdvanceDays;	\

#endif
#ifndef CopyFuseRuleEntity
#define CopyFuseRuleEntity(target,source)	\
			CopyPriceBindingRuleEntity(target,source);	\
			(target)->PriceLimitDuration=(source)->PriceLimitDuration;	\
			(target)->FuseDuration=(source)->FuseDuration;	\
			(target)->TradingFlag=(source)->TradingFlag;	\
			(target)->NoFuseTime=(source)->NoFuseTime;	\
			(target)->NoFuseDay=(source)->NoFuseDay;	\

#endif
#ifndef CopyCurrFuseEntity
#define CopyCurrFuseEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			CopyFuseRuleEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopyCurrNoTradingEntity
#define CopyCurrNoTradingEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopyAccountBaseEntity
#define CopyAccountBaseEntity(target,source)	\
			(target)->PreBalance=(source)->PreBalance;	\
			(target)->CurrMargin=(source)->CurrMargin;	\
			(target)->CloseProfit=(source)->CloseProfit;	\
			(target)->Premium=(source)->Premium;	\
			(target)->Deposit=(source)->Deposit;	\
			(target)->Withdraw=(source)->Withdraw;	\
			(target)->Balance=(source)->Balance;	\
			(target)->Available=(source)->Available;	\

#endif
#ifndef CopyAccountDetailEntity
#define CopyAccountDetailEntity(target,source)	\
			(target)->DateAccountOpen=(source)->DateAccountOpen;	\
			(target)->PreDate=(source)->PreDate;	\
			(target)->PreSettlementID=(source)->PreSettlementID;	\
			(target)->PreMargin=(source)->PreMargin;	\
			(target)->FuturesMargin=(source)->FuturesMargin;	\
			(target)->OptionsMargin=(source)->OptionsMargin;	\
			(target)->PositionProfit=(source)->PositionProfit;	\
			(target)->Profit=(source)->Profit;	\
			(target)->Interest=(source)->Interest;	\
			(target)->Fee=(source)->Fee;	\
			(target)->TotalCollateral=(source)->TotalCollateral;	\
			(target)->CollateralForMargin=(source)->CollateralForMargin;	\
			(target)->PreAccmulateInterest=(source)->PreAccmulateInterest;	\
			(target)->AccumulateInterest=(source)->AccumulateInterest;	\
			(target)->AccumulateFee=(source)->AccumulateFee;	\
			(target)->ForzenDeposit=(source)->ForzenDeposit;	\
			(target)->AccountStatus=(source)->AccountStatus;	\

#endif
#ifndef CopyAccountInfoEntity
#define CopyAccountInfoEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyAccountBaseEntity(target,source);	\
			CopyAccountDetailEntity(target,source);	\
			(target)->AccountID=(source)->AccountID;	\

#endif
#ifndef CopyTradingAccountEntity
#define CopyTradingAccountEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyAccountBaseEntity(target,source);	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->FrozenMargin=(source)->FrozenMargin;	\
			(target)->FrozenPremium=(source)->FrozenPremium;	\

#endif
#ifndef CopyCreditLimitEntity
#define CopyCreditLimitEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyAccountBaseEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->FrozenMargin=(source)->FrozenMargin;	\
			(target)->FrozenPremium=(source)->FrozenPremium;	\

#endif
#ifndef CopyBaseReserveAccountEntity
#define CopyBaseReserveAccountEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->Reserve=(source)->Reserve;	\

#endif
#ifndef CopyBasePositionEntity
#define CopyBasePositionEntity(target,source)	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->YdPosition=(source)->YdPosition;	\
			(target)->Position=(source)->Position;	\

#endif
#ifndef CopyFrozenPositionEntity
#define CopyFrozenPositionEntity(target,source)	\
			(target)->LongFrozen=(source)->LongFrozen;	\
			(target)->ShortFrozen=(source)->ShortFrozen;	\
			(target)->YdLongFrozen=(source)->YdLongFrozen;	\
			(target)->YdShortFrozen=(source)->YdShortFrozen;	\

#endif
#ifndef CopyTradingPositionEntity
#define CopyTradingPositionEntity(target,source)	\
			CopyFrozenPositionEntity(target,source);	\
			(target)->BuyTradeVolume=(source)->BuyTradeVolume;	\
			(target)->SellTradeVolume=(source)->SellTradeVolume;	\
			(target)->PositionCost=(source)->PositionCost;	\
			(target)->YdPositionCost=(source)->YdPositionCost;	\
			(target)->UseMargin=(source)->UseMargin;	\
			(target)->FrozenMargin=(source)->FrozenMargin;	\
			(target)->LongFrozenMargin=(source)->LongFrozenMargin;	\
			(target)->ShortFrozenMargin=(source)->ShortFrozenMargin;	\
			(target)->FrozenPremium=(source)->FrozenPremium;	\

#endif
#ifndef CopyPartPositionEntity
#define CopyPartPositionEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBasePositionEntity(target,source);	\
			CopyFrozenPositionEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\

#endif
#ifndef CopyClientPositionEntity
#define CopyClientPositionEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBasePositionEntity(target,source);	\
			CopyTradingPositionEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\

#endif
#ifndef CopyMarginCalcAlgoRefEntity
#define CopyMarginCalcAlgoRefEntity(target,source)	\
			(target)->MarginCalcID=(source)->MarginCalcID;	\

#endif
#ifndef CopyMarginRateRuleEntity
#define CopyMarginRateRuleEntity(target,source)	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongMarginRatio=(source)->LongMarginRatio;	\
			(target)->ShortMarginRatio=(source)->ShortMarginRatio;	\

#endif
#ifndef CopyHedgeVolumeEntity
#define CopyHedgeVolumeEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->LongVolumeOriginal=(source)->LongVolumeOriginal;	\
			(target)->ShortVolumeOriginal=(source)->ShortVolumeOriginal;	\
			(target)->LongVolume=(source)->LongVolume;	\
			(target)->ShortVolume=(source)->ShortVolume;	\

#endif
#ifndef CopyInputOrderV1Entity
#define CopyInputOrderV1Entity(target,source)	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->OrderPriceType=(source)->OrderPriceType;	\
			(target)->Direction=(source)->Direction;	\
			(target)->CombOffsetFlag=(source)->CombOffsetFlag;	\
			(target)->CombHedgeFlag=(source)->CombHedgeFlag;	\
			(target)->LimitPrice=(source)->LimitPrice;	\
			(target)->VolumeTotalOriginal=(source)->VolumeTotalOriginal;	\
			(target)->TimeCondition=(source)->TimeCondition;	\
			(target)->GTDDate=(source)->GTDDate;	\
			(target)->VolumeCondition=(source)->VolumeCondition;	\
			(target)->MinVolume=(source)->MinVolume;	\
			(target)->ContingentCondition=(source)->ContingentCondition;	\
			(target)->StopPrice=(source)->StopPrice;	\
			(target)->ForceCloseReason=(source)->ForceCloseReason;	\
			(target)->OrderLocalID=(source)->OrderLocalID;	\
			(target)->IsAutoSuspend=(source)->IsAutoSuspend;	\

#endif
#ifndef CopyInputOrderEntity
#define CopyInputOrderEntity(target,source)	\
			CopyInputOrderV1Entity(target,source);	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyOrderEntity
#define CopyOrderEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyInputOrderV1Entity(target,source);	\
			(target)->OrderSource=(source)->OrderSource;	\
			(target)->OrderStatus=(source)->OrderStatus;	\
			(target)->OrderType=(source)->OrderType;	\
			(target)->VolumeTraded=(source)->VolumeTraded;	\
			(target)->VolumeTotal=(source)->VolumeTotal;	\
			(target)->InsertDate=(source)->InsertDate;	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->ActiveTime=(source)->ActiveTime;	\
			(target)->SuspendTime=(source)->SuspendTime;	\
			(target)->UpdateTime=(source)->UpdateTime;	\
			(target)->CancelTime=(source)->CancelTime;	\
			(target)->ActiveUserID=(source)->ActiveUserID;	\
			(target)->Priority=(source)->Priority;	\
			(target)->TimeSortID=(source)->TimeSortID;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyInputCombOrderV1Entity
#define CopyInputCombOrderV1Entity(target,source)	\
			(target)->CombOrderSysID=(source)->CombOrderSysID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->LimitPrice=(source)->LimitPrice;	\
			(target)->VolumeTotalOriginal=(source)->VolumeTotalOriginal;	\
			(target)->CombOrderLocalID=(source)->CombOrderLocalID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->InstrumentID1=(source)->InstrumentID1;	\
			(target)->Direction1=(source)->Direction1;	\
			(target)->LegMultiple1=(source)->LegMultiple1;	\
			(target)->OffsetFlag1=(source)->OffsetFlag1;	\
			(target)->HedgeFlag1=(source)->HedgeFlag1;	\
			(target)->InstrumentID2=(source)->InstrumentID2;	\
			(target)->Direction2=(source)->Direction2;	\
			(target)->LegMultiple2=(source)->LegMultiple2;	\
			(target)->OffsetFlag2=(source)->OffsetFlag2;	\
			(target)->HedgeFlag2=(source)->HedgeFlag2;	\
			(target)->InstrumentID3=(source)->InstrumentID3;	\
			(target)->Direction3=(source)->Direction3;	\
			(target)->LegMultiple3=(source)->LegMultiple3;	\
			(target)->OffsetFlag3=(source)->OffsetFlag3;	\
			(target)->HedgeFlag3=(source)->HedgeFlag3;	\
			(target)->InstrumentID4=(source)->InstrumentID4;	\
			(target)->Direction4=(source)->Direction4;	\
			(target)->LegMultiple4=(source)->LegMultiple4;	\
			(target)->OffsetFlag4=(source)->OffsetFlag4;	\
			(target)->HedgeFlag4=(source)->HedgeFlag4;	\

#endif
#ifndef CopyInputCombOrderEntity
#define CopyInputCombOrderEntity(target,source)	\
			CopyInputCombOrderV1Entity(target,source);	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyCombOrderEntity
#define CopyCombOrderEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyInputCombOrderV1Entity(target,source);	\
			(target)->OrderSource=(source)->OrderSource;	\
			(target)->VolumeTraded=(source)->VolumeTraded;	\
			(target)->VolumeTotal=(source)->VolumeTotal;	\
			(target)->InsertDate=(source)->InsertDate;	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyInputExecOrderV1Entity
#define CopyInputExecOrderV1Entity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ExecOrderLocalID=(source)->ExecOrderLocalID;	\
			(target)->Volume=(source)->Volume;	\
			(target)->OffsetFlag=(source)->OffsetFlag;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->ReservePositionFlag=(source)->ReservePositionFlag;	\
			(target)->CloseFlag=(source)->CloseFlag;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\

#endif
#ifndef CopyInputExecOrderEntity
#define CopyInputExecOrderEntity(target,source)	\
			CopyInputExecOrderV1Entity(target,source);	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyExecOrderEntity
#define CopyExecOrderEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyInputExecOrderV1Entity(target,source);	\
			(target)->ExecOrderSysID=(source)->ExecOrderSysID;	\
			(target)->InsertDate=(source)->InsertDate;	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->CancelTime=(source)->CancelTime;	\
			(target)->ExecResult=(source)->ExecResult;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyInputAbandonExecOrderV1Entity
#define CopyInputAbandonExecOrderV1Entity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->AbandonExecOrderLocalID=(source)->AbandonExecOrderLocalID;	\
			(target)->Volume=(source)->Volume;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\

#endif
#ifndef CopyInputAbandonExecOrderEntity
#define CopyInputAbandonExecOrderEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->AbandonExecOrderLocalID=(source)->AbandonExecOrderLocalID;	\
			(target)->Volume=(source)->Volume;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyAbandonExecOrderEntity
#define CopyAbandonExecOrderEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyInputAbandonExecOrderV1Entity(target,source);	\
			(target)->AbandonExecOrderSysID=(source)->AbandonExecOrderSysID;	\
			(target)->InsertDate=(source)->InsertDate;	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->CancelTime=(source)->CancelTime;	\
			(target)->AbandonExecResult=(source)->AbandonExecResult;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyMdPubStatusEntity
#define CopyMdPubStatusEntity(target,source)	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->InstrumentStatus=(source)->InstrumentStatus;	\
			(target)->MdPubStatus=(source)->MdPubStatus;	\

#endif
#ifndef CopyMarketDataEntity
#define CopyMarketDataEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBaseMarketDataEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyMBLMarketDataEntity
#define CopyMBLMarketDataEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->Price=(source)->Price;	\
			(target)->Volume=(source)->Volume;	\

#endif
#ifndef CopyDepthMarketDataV1Entity
#define CopyDepthMarketDataV1Entity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBaseMarketDataEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->BidPrice1=(source)->BidPrice1;	\
			(target)->BidVolume1=(source)->BidVolume1;	\
			(target)->AskPrice1=(source)->AskPrice1;	\
			(target)->AskVolume1=(source)->AskVolume1;	\
			(target)->BidPrice2=(source)->BidPrice2;	\
			(target)->BidVolume2=(source)->BidVolume2;	\
			(target)->AskPrice2=(source)->AskPrice2;	\
			(target)->AskVolume2=(source)->AskVolume2;	\
			(target)->BidPrice3=(source)->BidPrice3;	\
			(target)->BidVolume3=(source)->BidVolume3;	\
			(target)->AskPrice3=(source)->AskPrice3;	\
			(target)->AskVolume3=(source)->AskVolume3;	\
			(target)->BidPrice4=(source)->BidPrice4;	\
			(target)->BidVolume4=(source)->BidVolume4;	\
			(target)->AskPrice4=(source)->AskPrice4;	\
			(target)->AskVolume4=(source)->AskVolume4;	\
			(target)->BidPrice5=(source)->BidPrice5;	\
			(target)->BidVolume5=(source)->BidVolume5;	\
			(target)->AskPrice5=(source)->AskPrice5;	\
			(target)->AskVolume5=(source)->AskVolume5;	\

#endif
#ifndef CopyDepthMarketDataEntity
#define CopyDepthMarketDataEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBaseMarketDataEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->BidPrice1=(source)->BidPrice1;	\
			(target)->BidVolume1=(source)->BidVolume1;	\
			(target)->AskPrice1=(source)->AskPrice1;	\
			(target)->AskVolume1=(source)->AskVolume1;	\
			(target)->BidPrice2=(source)->BidPrice2;	\
			(target)->BidVolume2=(source)->BidVolume2;	\
			(target)->AskPrice2=(source)->AskPrice2;	\
			(target)->AskVolume2=(source)->AskVolume2;	\
			(target)->BidPrice3=(source)->BidPrice3;	\
			(target)->BidVolume3=(source)->BidVolume3;	\
			(target)->AskPrice3=(source)->AskPrice3;	\
			(target)->AskVolume3=(source)->AskVolume3;	\
			(target)->BidPrice4=(source)->BidPrice4;	\
			(target)->BidVolume4=(source)->BidVolume4;	\
			(target)->AskPrice4=(source)->AskPrice4;	\
			(target)->AskVolume4=(source)->AskVolume4;	\
			(target)->BidPrice5=(source)->BidPrice5;	\
			(target)->BidVolume5=(source)->BidVolume5;	\
			(target)->AskPrice5=(source)->AskPrice5;	\
			(target)->AskVolume5=(source)->AskVolume5;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyDepthMarketDataDetailEntity
#define CopyDepthMarketDataDetailEntity(target,source)	\
			CopyDepthMarketDataV1Entity(target,source);	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyTopicDepthMarketDataDetailEntity
#define CopyTopicDepthMarketDataDetailEntity(target,source)	\
			CopyDepthMarketDataDetailEntity(target,source);	\
			(target)->TopicID=(source)->TopicID;	\

#endif
#ifndef CopyBaseIndexDataEntity
#define CopyBaseIndexDataEntity(target,source)	\
			(target)->LastPrice=(source)->LastPrice;	\
			(target)->PreClosePrice=(source)->PreClosePrice;	\
			(target)->OpenPrice=(source)->OpenPrice;	\
			(target)->HighestPrice=(source)->HighestPrice;	\
			(target)->LowestPrice=(source)->LowestPrice;	\
			(target)->ClosePrice=(source)->ClosePrice;	\
			(target)->UpdateTime=(source)->UpdateTime;	\
			(target)->UpdateMillisec=(source)->UpdateMillisec;	\

#endif
#ifndef CopyIndexDataEntity
#define CopyIndexDataEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBaseIndexDataEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyIndexDataDetailEntity
#define CopyIndexDataDetailEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyBaseIndexDataEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->TopicID=(source)->TopicID;	\

#endif
#ifndef CopyCurrentTimeSnapShotEntity
#define CopyCurrentTimeSnapShotEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->CurrDate=(source)->CurrDate;	\
			(target)->CurrTime=(source)->CurrTime;	\
			(target)->CurrMillisec=(source)->CurrMillisec;	\

#endif
#ifndef CopyBaseMarketDataEntity
#define CopyBaseMarketDataEntity(target,source)	\
			(target)->LastPrice=(source)->LastPrice;	\
			(target)->PreSettlementPrice=(source)->PreSettlementPrice;	\
			(target)->PreClosePrice=(source)->PreClosePrice;	\
			(target)->PreOpenInterest=(source)->PreOpenInterest;	\
			(target)->OpenPrice=(source)->OpenPrice;	\
			(target)->HighestPrice=(source)->HighestPrice;	\
			(target)->LowestPrice=(source)->LowestPrice;	\
			(target)->Volume=(source)->Volume;	\
			(target)->Turnover=(source)->Turnover;	\
			(target)->OpenInterest=(source)->OpenInterest;	\
			(target)->ClosePrice=(source)->ClosePrice;	\
			(target)->SettlementPrice=(source)->SettlementPrice;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\
			(target)->PreDelta=(source)->PreDelta;	\
			(target)->CurrDelta=(source)->CurrDelta;	\
			(target)->UpdateTime=(source)->UpdateTime;	\
			(target)->UpdateMillisec=(source)->UpdateMillisec;	\

#endif
#ifndef CopyHedgeDetailEntity
#define CopyHedgeDetailEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->HedgeQuotaSN=(source)->HedgeQuotaSN;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->Time=(source)->Time;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->TradingVolume=(source)->TradingVolume;	\
			(target)->HedgeQuota=(source)->HedgeQuota;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\

#endif
#ifndef CopyCurrHedgeEntity
#define CopyCurrHedgeEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->HedgeQuotaSN=(source)->HedgeQuotaSN;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->Time=(source)->Time;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->CurrVolume=(source)->CurrVolume;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\

#endif
#ifndef CopyTransactionDetailEntity
#define CopyTransactionDetailEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->BillSN=(source)->BillSN;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->Time=(source)->Time;	\
			(target)->ParticipantAccount=(source)->ParticipantAccount;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->Amount=(source)->Amount;	\
			(target)->AccountActionType=(source)->AccountActionType;	\
			(target)->Digest=(source)->Digest;	\

#endif
#ifndef CopyInputOTCOrderV1Entity
#define CopyInputOTCOrderV1Entity(target,source)	\
			(target)->OTCOrderSysID=(source)->OTCOrderSysID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->OffsetFlag=(source)->OffsetFlag;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->Price=(source)->Price;	\
			(target)->Volume=(source)->Volume;	\
			(target)->OtherParticipantID=(source)->OtherParticipantID;	\
			(target)->OtherClientID=(source)->OtherClientID;	\
			(target)->OtherUserID=(source)->OtherUserID;	\
			(target)->OtherOffsetFlag=(source)->OtherOffsetFlag;	\
			(target)->OtherHedgeFlag=(source)->OtherHedgeFlag;	\
			(target)->OTCOrderLocalID=(source)->OTCOrderLocalID;	\

#endif
#ifndef CopyInputOTCOrderEntity
#define CopyInputOTCOrderEntity(target,source)	\
			CopyInputOTCOrderV1Entity(target,source);	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->EfpInstrumentID=(source)->EfpInstrumentID;	\

#endif
#ifndef CopyOTCOrderEntity
#define CopyOTCOrderEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyInputOTCOrderV1Entity(target,source);	\
			(target)->OTCOrderStatus=(source)->OTCOrderStatus;	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->CancelTime=(source)->CancelTime;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->OtherClearingPartID=(source)->OtherClearingPartID;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->EfpInstrumentID=(source)->EfpInstrumentID;	\
			(target)->ReservePositionFlag=(source)->ReservePositionFlag;	\
			(target)->DeliveryMode=(source)->DeliveryMode;	\

#endif
#ifndef CopyInputQuoteV1Entity
#define CopyInputQuoteV1Entity(target,source)	\
			(target)->QuoteSysID=(source)->QuoteSysID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->Volume=(source)->Volume;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->QuoteLocalID=(source)->QuoteLocalID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BidCombOffsetFlag=(source)->BidCombOffsetFlag;	\
			(target)->BidCombHedgeFlag=(source)->BidCombHedgeFlag;	\
			(target)->BidPrice=(source)->BidPrice;	\
			(target)->AskCombOffsetFlag=(source)->AskCombOffsetFlag;	\
			(target)->AskCombHedgeFlag=(source)->AskCombHedgeFlag;	\
			(target)->AskPrice=(source)->AskPrice;	\

#endif
#ifndef CopyInputQuoteEntity
#define CopyInputQuoteEntity(target,source)	\
			CopyInputQuoteV1Entity(target,source);	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyQuoteEntity
#define CopyQuoteEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			CopyInputQuoteV1Entity(target,source);	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->CancelTime=(source)->CancelTime;	\
			(target)->TradeTime=(source)->TradeTime;	\
			(target)->BidOrderSysID=(source)->BidOrderSysID;	\
			(target)->AskOrderSysID=(source)->AskOrderSysID;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->ActionDay=(source)->ActionDay;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MacAddress=(source)->MacAddress;	\

#endif
#ifndef CopyTradeEntity
#define CopyTradeEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->TradeID=(source)->TradeID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->OffsetFlag=(source)->OffsetFlag;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->Price=(source)->Price;	\
			(target)->Volume=(source)->Volume;	\
			(target)->TradeTime=(source)->TradeTime;	\
			(target)->TradeType=(source)->TradeType;	\
			(target)->PriceSource=(source)->PriceSource;	\
			(target)->UserID=(source)->UserID;	\
			(target)->OrderLocalID=(source)->OrderLocalID;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->BusinessLocalID=(source)->BusinessLocalID;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyUserSessionEntity
#define CopyUserSessionEntity(target,source)	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserType=(source)->UserType;	\
			(target)->SessionID=(source)->SessionID;	\
			(target)->LoginTime=(source)->LoginTime;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->UserProductInfo=(source)->UserProductInfo;	\
			(target)->InterfaceProductInfo=(source)->InterfaceProductInfo;	\
			(target)->ProtocolInfo=(source)->ProtocolInfo;	\
			(target)->SessionType=(source)->SessionType;	\

#endif
#ifndef CopyFrontStatusEntity
#define CopyFrontStatusEntity(target,source)	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->LastReportTime=(source)->LastReportTime;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->LastReportDate=(source)->LastReportDate;	\

#endif
#ifndef CopyBulletinEntity
#define CopyBulletinEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->BulletinID=(source)->BulletinID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->NewsType=(source)->NewsType;	\
			(target)->NewsUrgency=(source)->NewsUrgency;	\
			(target)->SendTime=(source)->SendTime;	\
			(target)->Abstract=(source)->Abstract;	\
			(target)->ComeFrom=(source)->ComeFrom;	\
			(target)->Content=(source)->Content;	\
			(target)->URLLink=(source)->URLLink;	\
			(target)->MarketID=(source)->MarketID;	\

#endif
#ifndef CopyInformationEntity
#define CopyInformationEntity(target,source)	\
			(target)->InformationID=(source)->InformationID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->Content=(source)->Content;	\
			(target)->ContentLength=(source)->ContentLength;	\
			(target)->IsAccomplished=(source)->IsAccomplished;	\

#endif
#ifndef CopyOperationLogEntity
#define CopyOperationLogEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->Time=(source)->Time;	\
			(target)->OperationType=(source)->OperationType;	\
			(target)->OperationMemo=(source)->OperationMemo;	\

#endif
#ifndef CopyCommodityEntity
#define CopyCommodityEntity(target,source)	\
			(target)->CommodityName=(source)->CommodityName;	\
			(target)->CommodityID=(source)->CommodityID;	\
			(target)->QuantityUnit=(source)->QuantityUnit;	\
			(target)->PriceDecimal=(source)->PriceDecimal;	\

#endif
#ifndef CopyCalendarEntity
#define CopyCalendarEntity(target,source)	\
			(target)->Year=(source)->Year;	\
			(target)->Month=(source)->Month;	\
			(target)->Day=(source)->Day;	\
			(target)->Dat=(source)->Dat;	\
			(target)->Wrk=(source)->Wrk;	\
			(target)->Tra=(source)->Tra;	\
			(target)->Sun=(source)->Sun;	\
			(target)->Mon=(source)->Mon;	\
			(target)->Tue=(source)->Tue;	\
			(target)->Wed=(source)->Wed;	\
			(target)->Thu=(source)->Thu;	\
			(target)->Fri=(source)->Fri;	\
			(target)->Sat=(source)->Sat;	\
			(target)->Str=(source)->Str;	\
			(target)->End=(source)->End;	\
			(target)->Spr=(source)->Spr;	\

#endif
#ifndef CopyDataCenterDescEntity
#define CopyDataCenterDescEntity(target,source)	\
			(target)->DataCenterID=(source)->DataCenterID;	\
			(target)->StartMode=(source)->StartMode;	\

#endif
#ifndef CopyPartySequenceNoEntity
#define CopyPartySequenceNoEntity(target,source)	\
			(target)->PartyType=(source)->PartyType;	\
			(target)->PartyLenth=(source)->PartyLenth;	\
			(target)->StartNo=(source)->StartNo;	\
			(target)->NextNo=(source)->NextNo;	\
			(target)->MaxNo=(source)->MaxNo;	\
			(target)->StepSize=(source)->StepSize;	\

#endif
#ifndef CopyAttachmentEntity
#define CopyAttachmentEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->AttachmentRefType=(source)->AttachmentRefType;	\
			(target)->AttachmentRefID=(source)->AttachmentRefID;	\
			(target)->AttachmentPath=(source)->AttachmentPath;	\
			(target)->AttachmentFileName=(source)->AttachmentFileName;	\
			(target)->AttachmentTitle=(source)->AttachmentTitle;	\

#endif
#ifndef CopyArchiveLogEntity
#define CopyArchiveLogEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->ArchiveOperator=(source)->ArchiveOperator;	\
			(target)->ArchiveDate=(source)->ArchiveDate;	\
			(target)->ArchiveTime=(source)->ArchiveTime;	\
			(target)->ArchiveStatus=(source)->ArchiveStatus;	\
			(target)->ArchiveRemark=(source)->ArchiveRemark;	\

#endif
#ifndef CopyBaseObjectEntity
#define CopyBaseObjectEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->CreateDate=(source)->CreateDate;	\
			(target)->UpdateDate=(source)->UpdateDate;	\
			(target)->Creater=(source)->Creater;	\
			(target)->Updater=(source)->Updater;	\
			(target)->CreateSystem=(source)->CreateSystem;	\
			(target)->UpdateSystem=(source)->UpdateSystem;	\
			(target)->ObjectStatus=(source)->ObjectStatus;	\
			(target)->BuizCreateDate=(source)->BuizCreateDate;	\
			(target)->BuizUpdateDate=(source)->BuizUpdateDate;	\

#endif
#ifndef CopyBaseBizPartyEntity
#define CopyBaseBizPartyEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->PartyID=(source)->PartyID;	\
			(target)->RefProfileID=(source)->RefProfileID;	\
			(target)->RefProfileType=(source)->RefProfileType;	\

#endif
#ifndef CopySystemObjectEntity
#define CopySystemObjectEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->CreateDate=(source)->CreateDate;	\
			(target)->UpdateDate=(source)->UpdateDate;	\
			(target)->Creater=(source)->Creater;	\
			(target)->Updater=(source)->Updater;	\
			(target)->ObjectStatus=(source)->ObjectStatus;	\

#endif
#ifndef CopyLocationInfoEntity
#define CopyLocationInfoEntity(target,source)	\
			(target)->Country=(source)->Country;	\
			(target)->Region=(source)->Region;	\
			(target)->Province=(source)->Province;	\
			(target)->City=(source)->City;	\

#endif
#ifndef CopyAddressInfoEntity
#define CopyAddressInfoEntity(target,source)	\
			CopyLocationInfoEntity(target,source);	\
			(target)->Address=(source)->Address;	\
			(target)->ZipCode=(source)->ZipCode;	\
			(target)->EnglishAddress=(source)->EnglishAddress;	\

#endif
#ifndef CopyIndividualContactInfoEntity
#define CopyIndividualContactInfoEntity(target,source)	\
			CopyAddressInfoEntity(target,source);	\
			(target)->HomePhone=(source)->HomePhone;	\
			(target)->OfficePhone=(source)->OfficePhone;	\
			(target)->MobilePhone=(source)->MobilePhone;	\
			(target)->Fax=(source)->Fax;	\
			(target)->EMail=(source)->EMail;	\
			(target)->Website=(source)->Website;	\

#endif
#ifndef CopyCompanyContactInfoEntity
#define CopyCompanyContactInfoEntity(target,source)	\
			CopyAddressInfoEntity(target,source);	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->Telephone2=(source)->Telephone2;	\
			(target)->Fax=(source)->Fax;	\
			(target)->EMail=(source)->EMail;	\
			(target)->Website=(source)->Website;	\

#endif
#ifndef CopyCompanyProfileEntity
#define CopyCompanyProfileEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			CopyCompanyContactInfoEntity(target,source);	\
			(target)->CompanyName=(source)->CompanyName;	\
			(target)->EnglishName=(source)->EnglishName;	\
			(target)->EID=(source)->EID;	\
			(target)->LicenseNo=(source)->LicenseNo;	\
			(target)->TaxNo=(source)->TaxNo;	\
			(target)->CompanyType=(source)->CompanyType;	\
			(target)->Industry=(source)->Industry;	\
			(target)->IndustrySubClass=(source)->IndustrySubClass;	\
			(target)->BusinessScope=(source)->BusinessScope;	\
			(target)->Capital=(source)->Capital;	\
			(target)->CapitalCurrency=(source)->CapitalCurrency;	\
			(target)->ArtificialPerson=(source)->ArtificialPerson;	\
			(target)->ContactName=(source)->ContactName;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyIndividualProfileEntity
#define CopyIndividualProfileEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			CopyIndividualContactInfoEntity(target,source);	\
			(target)->IndividualName=(source)->IndividualName;	\
			(target)->Gender=(source)->Gender;	\
			(target)->Birthday=(source)->Birthday;	\
			(target)->MarriageStatus=(source)->MarriageStatus;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->NativePlace=(source)->NativePlace;	\
			(target)->People=(source)->People;	\
			(target)->PoliticalStatus=(source)->PoliticalStatus;	\
			(target)->Employer=(source)->Employer;	\
			(target)->Profession=(source)->Profession;	\
			(target)->Remark=(source)->Remark;	\
			(target)->Nationality=(source)->Nationality;	\

#endif
#ifndef CopyMemberBasicProfileEntity
#define CopyMemberBasicProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->ShortName=(source)->ShortName;	\
			(target)->CertCode=(source)->CertCode;	\
			(target)->MemberType=(source)->MemberType;	\
			(target)->Grade=(source)->Grade;	\
			(target)->OpenAccountBankName=(source)->OpenAccountBankName;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->JoinDate=(source)->JoinDate;	\
			(target)->QuitDate=(source)->QuitDate;	\
			(target)->QuitReason=(source)->QuitReason;	\
			(target)->OnfloorTelephone=(source)->OnfloorTelephone;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyParticipantTypeEntity
#define CopyParticipantTypeEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->MemberType=(source)->MemberType;	\

#endif
#ifndef CopyContactProfileEntity
#define CopyContactProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->ContactRole=(source)->ContactRole;	\
			(target)->ContactQualCertType=(source)->ContactQualCertType;	\
			(target)->ContactCertificateNo=(source)->ContactCertificateNo;	\

#endif
#ifndef CopyMemberAnnualSurveyEntity
#define CopyMemberAnnualSurveyEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->MemberID=(source)->MemberID;	\
			(target)->Year=(source)->Year;	\
			(target)->IsPassed=(source)->IsPassed;	\
			(target)->Passedperson=(source)->Passedperson;	\
			(target)->ContactID=(source)->ContactID;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyClientAnnualSurveyEntity
#define CopyClientAnnualSurveyEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->ClientId=(source)->ClientId;	\
			(target)->SurveyDate=(source)->SurveyDate;	\
			(target)->SurveyTime=(source)->SurveyTime;	\
			(target)->Status=(source)->Status;	\
			(target)->ContactID=(source)->ContactID;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyMemberBranchEntity
#define CopyMemberBranchEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			CopyCompanyContactInfoEntity(target,source);	\
			(target)->MemberID=(source)->MemberID;	\
			(target)->BranchName=(source)->BranchName;	\
			(target)->BusinessOpenDate=(source)->BusinessOpenDate;	\
			(target)->BusinessCloseDate=(source)->BusinessCloseDate;	\
			(target)->BranchContactName=(source)->BranchContactName;	\

#endif
#ifndef CopyMemberStockHolderEntity
#define CopyMemberStockHolderEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->StockAmt=(source)->StockAmt;	\
			(target)->StockPercent=(source)->StockPercent;	\
			(target)->StockHolderType=(source)->StockHolderType;	\
			(target)->StockHolderClass=(source)->StockHolderClass;	\
			(target)->StockHolderCode=(source)->StockHolderCode;	\

#endif
#ifndef CopyMemberSeatEntity
#define CopyMemberSeatEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->MemberId=(source)->MemberId;	\
			(target)->MemberSeatCode=(source)->MemberSeatCode;	\
			(target)->DDDtel=(source)->DDDtel;	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->DeliveryDate=(source)->DeliveryDate;	\
			(target)->ApprovedDate=(source)->ApprovedDate;	\
			(target)->EnterDate=(source)->EnterDate;	\
			(target)->OnfloorTelClose=(source)->OnfloorTelClose;	\
			(target)->ThirdFloorTel=(source)->ThirdFloorTel;	\

#endif
#ifndef CopyMemberOffFloorSeatEntity
#define CopyMemberOffFloorSeatEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			CopyCompanyContactInfoEntity(target,source);	\
			(target)->MemberId=(source)->MemberId;	\
			(target)->SeatType=(source)->SeatType;	\
			(target)->StatFlag=(source)->StatFlag;	\
			(target)->Software=(source)->Software;	\
			(target)->FundTransfer=(source)->FundTransfer;	\
			(target)->CommunicateType=(source)->CommunicateType;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->ProtocolDate=(source)->ProtocolDate;	\
			(target)->RevisionCode=(source)->RevisionCode;	\
			(target)->MemberOffFloorSeatCode=(source)->MemberOffFloorSeatCode;	\

#endif
#ifndef CopyMemberOffFloorSeatContactEntity
#define CopyMemberOffFloorSeatContactEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->OffFloorSeatId=(source)->OffFloorSeatId;	\
			(target)->ContactId=(source)->ContactId;	\
			(target)->MemOffFloorSeatContactRole=(source)->MemOffFloorSeatContactRole;	\
			(target)->QualCertName=(source)->QualCertName;	\
			(target)->QualCertCode=(source)->QualCertCode;	\

#endif
#ifndef CopyClientBasicProfileEntity
#define CopyClientBasicProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->OpenAccountBankName=(source)->OpenAccountBankName;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->OpenAccountDate=(source)->OpenAccountDate;	\
			(target)->CloseaccountDate=(source)->CloseaccountDate;	\
			(target)->CloseAccountReason=(source)->CloseAccountReason;	\
			(target)->RefMemberID=(source)->RefMemberID;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyClientCancelReqFormEntity
#define CopyClientCancelReqFormEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->RequestID=(source)->RequestID;	\
			(target)->MemberPartyID=(source)->MemberPartyID;	\
			(target)->ClientPartyID=(source)->ClientPartyID;	\
			(target)->CancelReqDate=(source)->CancelReqDate;	\
			(target)->CancelDate=(source)->CancelDate;	\
			(target)->ProcessStatus=(source)->ProcessStatus;	\
			(target)->ApplyRemark=(source)->ApplyRemark;	\
			(target)->AuditRemark=(source)->AuditRemark;	\

#endif
#ifndef CopyRepresentativeBasicProfileEntity
#define CopyRepresentativeBasicProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->SystemUserID=(source)->SystemUserID;	\
			(target)->RepresentativeCode=(source)->RepresentativeCode;	\
			(target)->RepresentativeType=(source)->RepresentativeType;	\
			(target)->CertificateNo=(source)->CertificateNo;	\
			(target)->QualCertType=(source)->QualCertType;	\
			(target)->RegisterDate=(source)->RegisterDate;	\
			(target)->RepealDate=(source)->RepealDate;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyDepartmentBasicProfileEntity
#define CopyDepartmentBasicProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->DepartmentName=(source)->DepartmentName;	\
			(target)->DepartmentDesc=(source)->DepartmentDesc;	\

#endif
#ifndef CopyEmployeeBasicProfileEntity
#define CopyEmployeeBasicProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->EmployeeName=(source)->EmployeeName;	\
			(target)->EmployeeCode=(source)->EmployeeCode;	\
			(target)->Headship=(source)->Headship;	\
			(target)->OndutyDate=(source)->OndutyDate;	\
			(target)->SystemUserID=(source)->SystemUserID;	\
			(target)->DimissionDate=(source)->DimissionDate;	\

#endif
#ifndef CopyBlacklistBasicEntity
#define CopyBlacklistBasicEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->BlacklistType=(source)->BlacklistType;	\
			(target)->ValidDate=(source)->ValidDate;	\
			(target)->ExpiryDate=(source)->ExpiryDate;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyMarketDataProviderBasicProfileEntity
#define CopyMarketDataProviderBasicProfileEntity(target,source)	\
			CopyBaseBizPartyEntity(target,source);	\
			(target)->PartyShortName=(source)->PartyShortName;	\
			(target)->DataProviderCertCode=(source)->DataProviderCertCode;	\
			(target)->OnfloorTelephone=(source)->OnfloorTelephone;	\
			(target)->JoinDate=(source)->JoinDate;	\
			(target)->QuitDate=(source)->QuitDate;	\
			(target)->QuitReason=(source)->QuitReason;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyMarketDataProvTerminalEntity
#define CopyMarketDataProvTerminalEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->MarketDataProviderId=(source)->MarketDataProviderId;	\
			(target)->DDDtel=(source)->DDDtel;	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->DeliveryDate=(source)->DeliveryDate;	\
			(target)->ApprovedDate=(source)->ApprovedDate;	\
			(target)->EnterDate=(source)->EnterDate;	\
			(target)->OnfloortelClose=(source)->OnfloortelClose;	\
			(target)->ThirdFloorTel=(source)->ThirdFloorTel;	\

#endif
#ifndef CopyOperatorEntity
#define CopyOperatorEntity(target,source)	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OperatorType=(source)->OperatorType;	\

#endif
#ifndef CopyUserRoleEntity
#define CopyUserRoleEntity(target,source)	\
			(target)->SystemUserID=(source)->SystemUserID;	\
			(target)->RoleID=(source)->RoleID;	\

#endif
#ifndef CopySystemRoleEntity
#define CopySystemRoleEntity(target,source)	\
			(target)->RoleID=(source)->RoleID;	\
			(target)->RoleName=(source)->RoleName;	\
			(target)->RoleDesc=(source)->RoleDesc;	\

#endif
#ifndef CopyRoleGroupEntity
#define CopyRoleGroupEntity(target,source)	\
			(target)->RoleGroupID=(source)->RoleGroupID;	\
			(target)->RoleGroupName=(source)->RoleGroupName;	\
			(target)->RoleGroupDesc=(source)->RoleGroupDesc;	\

#endif
#ifndef CopyRoleFunctionEntity
#define CopyRoleFunctionEntity(target,source)	\
			(target)->RoleID=(source)->RoleID;	\
			(target)->FunctionCode=(source)->FunctionCode;	\

#endif
#ifndef CopyRoleGroupFunctionEntity
#define CopyRoleGroupFunctionEntity(target,source)	\
			(target)->RoleGroupID=(source)->RoleGroupID;	\
			(target)->FunctionCode=(source)->FunctionCode;	\

#endif
#ifndef CopyRoleGroupRoleEntity
#define CopyRoleGroupRoleEntity(target,source)	\
			(target)->RoleGroupID=(source)->RoleGroupID;	\
			(target)->RoleID=(source)->RoleID;	\

#endif
#ifndef CopySystemFunctionEntity
#define CopySystemFunctionEntity(target,source)	\
			(target)->FunctionCode=(source)->FunctionCode;	\
			(target)->FunctionName=(source)->FunctionName;	\
			(target)->FunctionDesc=(source)->FunctionDesc;	\

#endif
#ifndef CopyParameterTypeEntity
#define CopyParameterTypeEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->ParameterTypeName=(source)->ParameterTypeName;	\
			(target)->ParameterTypeDesc=(source)->ParameterTypeDesc;	\

#endif
#ifndef CopySystemParameterEntity
#define CopySystemParameterEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->ParameterTypeID=(source)->ParameterTypeID;	\
			(target)->ParameterValue=(source)->ParameterValue;	\
			(target)->ParameterDesc=(source)->ParameterDesc;	\

#endif
#ifndef CopyAccessRuleEntity
#define CopyAccessRuleEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->PartyID=(source)->PartyID;	\
			(target)->ResourceType=(source)->ResourceType;	\
			(target)->AccessRule=(source)->AccessRule;	\
			(target)->ResourceID=(source)->ResourceID;	\

#endif
#ifndef CopyAuthenUserEntity
#define CopyAuthenUserEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->AuthenUserID=(source)->AuthenUserID;	\
			(target)->AuthenUserTypeSN=(source)->AuthenUserTypeSN;	\
			(target)->AuthenUserName=(source)->AuthenUserName;	\
			(target)->Gender=(source)->Gender;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->EmployeeID=(source)->EmployeeID;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyAuthenUserTypeEntity
#define CopyAuthenUserTypeEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->TypeName=(source)->TypeName;	\
			(target)->TypeDesc=(source)->TypeDesc;	\

#endif
#ifndef CopyAuthenUserGroupEntity
#define CopyAuthenUserGroupEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->UserGroupName=(source)->UserGroupName;	\
			(target)->UserGroupDesc=(source)->UserGroupDesc;	\

#endif
#ifndef CopyAuthenSystemEntity
#define CopyAuthenSystemEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->SystemName=(source)->SystemName;	\
			(target)->SystemCode=(source)->SystemCode;	\
			(target)->SecurityLevel=(source)->SecurityLevel;	\
			(target)->SystemDesc=(source)->SystemDesc;	\

#endif
#ifndef CopyAuthenModeEntity
#define CopyAuthenModeEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->AuthenModeName=(source)->AuthenModeName;	\
			(target)->SecurityLevel=(source)->SecurityLevel;	\
			(target)->AuthenModeDesc=(source)->AuthenModeDesc;	\

#endif
#ifndef CopyUserStaticPasswordEntity
#define CopyUserStaticPasswordEntity(target,source)	\
			CopySystemObjectEntity(target,source);	\
			(target)->AuthenUserSN=(source)->AuthenUserSN;	\
			(target)->AuthenModeID=(source)->AuthenModeID;	\
			(target)->StaticPassword=(source)->StaticPassword;	\

#endif
#ifndef CopyCompClientRequestEntity
#define CopyCompClientRequestEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->RequestID=(source)->RequestID;	\
			(target)->CompanyName=(source)->CompanyName;	\
			(target)->EnglishName=(source)->EnglishName;	\
			(target)->EID=(source)->EID;	\
			(target)->LicenseNo=(source)->LicenseNo;	\
			(target)->TaxNo=(source)->TaxNo;	\
			(target)->CompanyType=(source)->CompanyType;	\
			(target)->Industry=(source)->Industry;	\
			(target)->IndustrySubClass=(source)->IndustrySubClass;	\
			(target)->BusinessScope=(source)->BusinessScope;	\
			(target)->Capital=(source)->Capital;	\
			(target)->CapitalCurrency=(source)->CapitalCurrency;	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->Telephone2=(source)->Telephone2;	\
			(target)->Fax=(source)->Fax;	\
			(target)->EMail=(source)->EMail;	\
			(target)->Website=(source)->Website;	\
			(target)->Country=(source)->Country;	\
			(target)->Region=(source)->Region;	\
			(target)->Province=(source)->Province;	\
			(target)->City=(source)->City;	\
			(target)->Address=(source)->Address;	\
			(target)->ZipCode=(source)->ZipCode;	\
			(target)->EnglishAddress=(source)->EnglishAddress;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->OpenAccountBankName=(source)->OpenAccountBankName;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->OpenAccountDate=(source)->OpenAccountDate;	\
			(target)->RefMemberPartyID=(source)->RefMemberPartyID;	\
			(target)->ProcessStatus=(source)->ProcessStatus;	\
			(target)->ArtificialPerson=(source)->ArtificialPerson;	\
			(target)->ContactName=(source)->ContactName;	\
			(target)->PartyID=(source)->PartyID;	\
			(target)->Remark=(source)->Remark;	\
			(target)->AuditRemark=(source)->AuditRemark;	\

#endif
#ifndef CopyIndiClientRequestEntity
#define CopyIndiClientRequestEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->RequestID=(source)->RequestID;	\
			(target)->IndividualName=(source)->IndividualName;	\
			(target)->Gender=(source)->Gender;	\
			(target)->Birthday=(source)->Birthday;	\
			(target)->MarriageStatus=(source)->MarriageStatus;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->NativePlace=(source)->NativePlace;	\
			(target)->People=(source)->People;	\
			(target)->PoliticalStatus=(source)->PoliticalStatus;	\
			(target)->Employer=(source)->Employer;	\
			(target)->Profession=(source)->Profession;	\
			(target)->Nationality=(source)->Nationality;	\
			(target)->HomePhone=(source)->HomePhone;	\
			(target)->OfficePhone=(source)->OfficePhone;	\
			(target)->MobilePhone=(source)->MobilePhone;	\
			(target)->Fax=(source)->Fax;	\
			(target)->EMail=(source)->EMail;	\
			(target)->Website=(source)->Website;	\
			(target)->Address=(source)->Address;	\
			(target)->ZipCode=(source)->ZipCode;	\
			(target)->EnglishAddress=(source)->EnglishAddress;	\
			(target)->Country=(source)->Country;	\
			(target)->Region=(source)->Region;	\
			(target)->Province=(source)->Province;	\
			(target)->City=(source)->City;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->OpenAccountBankName=(source)->OpenAccountBankName;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->OpenAccountDate=(source)->OpenAccountDate;	\
			(target)->RefMemberPartyID=(source)->RefMemberPartyID;	\
			(target)->ProcessStatus=(source)->ProcessStatus;	\
			(target)->PartyID=(source)->PartyID;	\
			(target)->Remark=(source)->Remark;	\
			(target)->AuditRemark=(source)->AuditRemark;	\

#endif
#ifndef CopyClientRegContactEntity
#define CopyClientRegContactEntity(target,source)	\
			CopyBaseObjectEntity(target,source);	\
			(target)->RequestID=(source)->RequestID;	\
			(target)->ContactRole=(source)->ContactRole;	\
			(target)->IndividualName=(source)->IndividualName;	\
			(target)->Gender=(source)->Gender;	\
			(target)->Birthday=(source)->Birthday;	\
			(target)->MarriageStatus=(source)->MarriageStatus;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->NativePlace=(source)->NativePlace;	\
			(target)->People=(source)->People;	\
			(target)->PoliticalStatus=(source)->PoliticalStatus;	\
			(target)->Employer=(source)->Employer;	\
			(target)->Profession=(source)->Profession;	\
			(target)->Nationality=(source)->Nationality;	\
			(target)->HomePhone=(source)->HomePhone;	\
			(target)->OfficePhone=(source)->OfficePhone;	\
			(target)->MobilePhone=(source)->MobilePhone;	\
			(target)->Fax=(source)->Fax;	\
			(target)->EMail=(source)->EMail;	\
			(target)->Website=(source)->Website;	\
			(target)->Address=(source)->Address;	\
			(target)->ZipCode=(source)->ZipCode;	\
			(target)->EnglishAddress=(source)->EnglishAddress;	\
			(target)->Country=(source)->Country;	\
			(target)->Province=(source)->Province;	\
			(target)->City=(source)->City;	\
			(target)->Region=(source)->Region;	\

#endif
#ifndef CopyCertificateEntity
#define CopyCertificateEntity(target,source)	\
			(target)->ObjectId=(source)->ObjectId;	\
			(target)->AuthenUserId=(source)->AuthenUserId;	\
			(target)->Department=(source)->Department;	\
			(target)->AuthenUserName=(source)->AuthenUserName;	\
			(target)->Address=(source)->Address;	\
			(target)->ZipCode=(source)->ZipCode;	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->Email=(source)->Email;	\
			(target)->Fax=(source)->Fax;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->ValidDate=(source)->ValidDate;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->CertificateNumber=(source)->CertificateNumber;	\
			(target)->ObjectStatus=(source)->ObjectStatus;	\
			(target)->CertificateSort=(source)->CertificateSort;	\
			(target)->CertificateType=(source)->CertificateType;	\
			(target)->Country=(source)->Country;	\
			(target)->Province=(source)->Province;	\
			(target)->ExportStatus=(source)->ExportStatus;	\

#endif
#ifndef CopyEWClientEntity
#define CopyEWClientEntity(target,source)	\
			(target)->System=(source)->System;	\
			(target)->System_Sort=(source)->System_Sort;	\
			(target)->Sort=(source)->Sort;	\
			(target)->Client_Name=(source)->Client_Name;	\
			(target)->Client_No=(source)->Client_No;	\
			(target)->Member_Code=(source)->Member_Code;	\
			(target)->Member_Code1=(source)->Member_Code1;	\
			(target)->Member_Code2=(source)->Member_Code2;	\
			(target)->Status=(source)->Status;	\
			(target)->ZJ_Code=(source)->ZJ_Code;	\
			(target)->Address=(source)->Address;	\
			(target)->ZipCode=(source)->ZipCode;	\
			(target)->TEL=(source)->TEL;	\
			(target)->Type=(source)->Type;	\
			(target)->Gender=(source)->Gender;	\
			(target)->Age=(source)->Age;	\
			(target)->PROFESSION=(source)->PROFESSION;	\
			(target)->KIND=(source)->KIND;	\
			(target)->DUTY_NO=(source)->DUTY_NO;	\
			(target)->REPRESENT=(source)->REPRESENT;	\
			(target)->CAPITAL=(source)->CAPITAL;	\
			(target)->BANK=(source)->BANK;	\
			(target)->BANK_ACCOUNT=(source)->BANK_ACCOUNT;	\
			(target)->BUSINESS=(source)->BUSINESS;	\
			(target)->CONTACT_P=(source)->CONTACT_P;	\
			(target)->SQ_NAME=(source)->SQ_NAME;	\
			(target)->SQ_ZJ_CODE=(source)->SQ_ZJ_CODE;	\
			(target)->SQ_TEL=(source)->SQ_TEL;	\
			(target)->SQ_ADDR=(source)->SQ_ADDR;	\
			(target)->SQ_ZIPCODE=(source)->SQ_ZIPCODE;	\
			(target)->XD_NAME=(source)->XD_NAME;	\
			(target)->XD_ZJ_CODE=(source)->XD_ZJ_CODE;	\
			(target)->XD_TEL=(source)->XD_TEL;	\
			(target)->XD_ADDR=(source)->XD_ADDR;	\
			(target)->XD_ZIPCODE=(source)->XD_ZIPCODE;	\
			(target)->ZJ_NAME=(source)->ZJ_NAME;	\
			(target)->ZJ_ZJ_CODE=(source)->ZJ_ZJ_CODE;	\
			(target)->ZJ_TEL=(source)->ZJ_TEL;	\
			(target)->ZJ_ADDR=(source)->ZJ_ADDR;	\
			(target)->ZJ_ZIPCODE=(source)->ZJ_ZIPCODE;	\
			(target)->JS_NAME=(source)->JS_NAME;	\
			(target)->JS_ZJ_CODE=(source)->JS_ZJ_CODE;	\
			(target)->JS_TEL=(source)->JS_TEL;	\
			(target)->JS_ADDR=(source)->JS_ADDR;	\
			(target)->JS_ZIPCODE=(source)->JS_ZIPCODE;	\
			(target)->Client_No2=(source)->Client_No2;	\
			(target)->Client_No3=(source)->Client_No3;	\
			(target)->KH_DATE=(source)->KH_DATE;	\
			(target)->KH_TIME=(source)->KH_TIME;	\
			(target)->KH_STATUS=(source)->KH_STATUS;	\
			(target)->XG_DATE=(source)->XG_DATE;	\
			(target)->XG_TIME=(source)->XG_TIME;	\
			(target)->SH_DATE=(source)->SH_DATE;	\
			(target)->SH_TIME=(source)->SH_TIME;	\
			(target)->SM=(source)->SM;	\

#endif
#ifndef CopyTBCommandEntity
#define CopyTBCommandEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->CommandNo=(source)->CommandNo;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->CommandDate=(source)->CommandDate;	\
			(target)->CommandTime=(source)->CommandTime;	\
			(target)->CommandType=(source)->CommandType;	\
			(target)->FieldName=(source)->FieldName;	\
			(target)->FieldContent=(source)->FieldContent;	\

#endif
#ifndef CopyTBCommandCounterEntity
#define CopyTBCommandCounterEntity(target,source)	\
			(target)->TBCommandCounter=(source)->TBCommandCounter;	\

#endif
#ifndef CopySelectOrderEntity
#define CopySelectOrderEntity(target,source)	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->OrderLocalID=(source)->OrderLocalID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopySelectQuoteEntity
#define CopySelectQuoteEntity(target,source)	\
			(target)->QuoteSysID=(source)->QuoteSysID;	\
			(target)->QuoteLocalID=(source)->QuoteLocalID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopyDBMetadataEntity
#define CopyDBMetadataEntity(target,source)	\
			(target)->SchemaID=(source)->SchemaID;	\
			(target)->TableGroupID=(source)->TableGroupID;	\
			(target)->TableID=(source)->TableID;	\
			(target)->FieldID=(source)->FieldID;	\
			(target)->FieldLabel=(source)->FieldLabel;	\
			(target)->FieldType=(source)->FieldType;	\
			(target)->OriginalType=(source)->OriginalType;	\
			(target)->BaseType=(source)->BaseType;	\
			(target)->IsKey=(source)->IsKey;	\
			(target)->IsNull=(source)->IsNull;	\
			(target)->FieldLength=(source)->FieldLength;	\
			(target)->FieldPrecision=(source)->FieldPrecision;	\

#endif
#ifndef CopyEnumMetadataEntity
#define CopyEnumMetadataEntity(target,source)	\
			(target)->EnumValueID=(source)->EnumValueID;	\
			(target)->EnumValueType=(source)->EnumValueType;	\
			(target)->EnumValueLabel=(source)->EnumValueLabel;	\
			(target)->EnumValueResult=(source)->EnumValueResult;	\

#endif
#ifndef CopyRangeMetadataEntity
#define CopyRangeMetadataEntity(target,source)	\
			(target)->RangeIntType=(source)->RangeIntType;	\
			(target)->RangeIntFrom=(source)->RangeIntFrom;	\
			(target)->RangeIntTo=(source)->RangeIntTo;	\

#endif
#ifndef CopyInterfaceMetadataEntity
#define CopyInterfaceMetadataEntity(target,source)	\
			(target)->InterfaceID=(source)->InterfaceID;	\
			(target)->InterfaceConfigID=(source)->InterfaceConfigID;	\
			(target)->InterfaceConfigType=(source)->InterfaceConfigType;	\
			(target)->SchemaID=(source)->SchemaID;	\
			(target)->TableGroupID=(source)->TableGroupID;	\
			(target)->TableID=(source)->TableID;	\
			(target)->FieldID=(source)->FieldID;	\
			(target)->DisplayType=(source)->DisplayType;	\
			(target)->EnumTable=(source)->EnumTable;	\
			(target)->EnumField=(source)->EnumField;	\
			(target)->EnumValue=(source)->EnumValue;	\
			(target)->ButtonType=(source)->ButtonType;	\
			(target)->OriginalValue=(source)->OriginalValue;	\
			(target)->CanBeChange=(source)->CanBeChange;	\
			(target)->IsRef=(source)->IsRef;	\
			(target)->RefName=(source)->RefName;	\
			(target)->IsVisible=(source)->IsVisible;	\

#endif
#ifndef CopyCalendarSetEntity
#define CopyCalendarSetEntity(target,source)	\
			(target)->CalYear=(source)->CalYear;	\
			(target)->CalMonth=(source)->CalMonth;	\
			(target)->CalType=(source)->CalType;	\
			(target)->CalSetType=(source)->CalSetType;	\
			(target)->CalName=(source)->CalName;	\
			(target)->CalValue=(source)->CalValue;	\

#endif
#ifndef CopyFunctionPropertyEntity
#define CopyFunctionPropertyEntity(target,source)	\
			(target)->FunctionCode=(source)->FunctionCode;	\
			(target)->FunctionKey=(source)->FunctionKey;	\
			(target)->IsMenu=(source)->IsMenu;	\

#endif
#ifndef CopyTBCommandMetadataEntity
#define CopyTBCommandMetadataEntity(target,source)	\
			(target)->SchemaID=(source)->SchemaID;	\
			(target)->TableID=(source)->TableID;	\
			(target)->CreateCommand=(source)->CreateCommand;	\
			(target)->UpdateCommand=(source)->UpdateCommand;	\
			(target)->DeleteCommand=(source)->DeleteCommand;	\

#endif
#ifndef CopyExchangeCounterEntity
#define CopyExchangeCounterEntity(target,source)	\
			(target)->ExchangeID=(source)->ExchangeID;	\
			(target)->Counter=(source)->Counter;	\

#endif
#ifndef CopySettlementGroupCounterEntity
#define CopySettlementGroupCounterEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->Counter=(source)->Counter;	\

#endif
#ifndef CopyTableLockEntity
#define CopyTableLockEntity(target,source)	\
			(target)->TableID=(source)->TableID;	\

#endif
#ifndef CopyRecordLockEntity
#define CopyRecordLockEntity(target,source)	\
			(target)->TableID=(source)->TableID;	\
			(target)->KeyValue=(source)->KeyValue;	\

#endif
#ifndef CopyUserLogoutEntity
#define CopyUserLogoutEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopyLoginBaseEntity
#define CopyLoginBaseEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->Password=(source)->Password;	\
			(target)->UserProductInfo=(source)->UserProductInfo;	\
			(target)->InterfaceProductInfo=(source)->InterfaceProductInfo;	\
			(target)->ProtocolInfo=(source)->ProtocolInfo;	\
			(target)->DataCenterID=(source)->DataCenterID;	\

#endif
#ifndef CopyLoginExtraEntity
#define CopyLoginExtraEntity(target,source)	\
			(target)->LoginTime=(source)->LoginTime;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->MaxOrderLocalID=(source)->MaxOrderLocalID;	\
			(target)->TradingSystemName=(source)->TradingSystemName;	\
			(target)->UserType=(source)->UserType;	\
			(target)->MaxCommFlux=(source)->MaxCommFlux;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyLoginFullEntity
#define CopyLoginFullEntity(target,source)	\
			CopyLoginBaseEntity(target,source);	\
			CopyLoginExtraEntity(target,source);	\

#endif
#ifndef CopyLoginRspEntity
#define CopyLoginRspEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->LoginTime=(source)->LoginTime;	\
			(target)->MaxOrderLocalID=(source)->MaxOrderLocalID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingSystemName=(source)->TradingSystemName;	\
			(target)->DataCenterID=(source)->DataCenterID;	\
			(target)->PrivateFlowSize=(source)->PrivateFlowSize;	\
			(target)->UserFlowSize=(source)->UserFlowSize;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyUserCommFluxControlEntity
#define CopyUserCommFluxControlEntity(target,source)	\
			(target)->MaxTradeCommFlux=(source)->MaxTradeCommFlux;	\
			(target)->MaxTradeOnWayCommFlux=(source)->MaxTradeOnWayCommFlux;	\
			(target)->MaxQueryCommFlux=(source)->MaxQueryCommFlux;	\
			(target)->MaxQueryOnWayCommFlux=(source)->MaxQueryOnWayCommFlux;	\

#endif
#ifndef CopyLoginInfoEntity
#define CopyLoginInfoEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserProductInfo=(source)->UserProductInfo;	\
			(target)->InterfaceProductInfo=(source)->InterfaceProductInfo;	\
			(target)->ProtocolInfo=(source)->ProtocolInfo;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->LoginType=(source)->LoginType;	\
			(target)->SessionType=(source)->SessionType;	\
			(target)->ErrorID=(source)->ErrorID;	\
			(target)->UpdateDate=(source)->UpdateDate;	\
			(target)->UpdateTime=(source)->UpdateTime;	\

#endif
#ifndef CopyUserCommFluxEntity
#define CopyUserCommFluxEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->MaxCommFlux=(source)->MaxCommFlux;	\

#endif
#ifndef CopyCommPhaseEntity
#define CopyCommPhaseEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->CommPhaseNo=(source)->CommPhaseNo;	\

#endif
#ifndef CopyExchangeTradingDayEntity
#define CopyExchangeTradingDayEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->ExchangeID=(source)->ExchangeID;	\

#endif
#ifndef CopyUserPasswordUpdateEntity
#define CopyUserPasswordUpdateEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->OldPassword=(source)->OldPassword;	\
			(target)->NewPassword=(source)->NewPassword;	\

#endif
#ifndef CopyTradeManagerPasswordUpdateEntity
#define CopyTradeManagerPasswordUpdateEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->OldPassword=(source)->OldPassword;	\
			(target)->NewPassword=(source)->NewPassword;	\

#endif
#ifndef CopyForceUserExitEntity
#define CopyForceUserExitEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyAccountDepositEntity
#define CopyAccountDepositEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->Account=(source)->Account;	\
			(target)->Deposit=(source)->Deposit;	\

#endif
#ifndef CopyMarketDataBaseEntity
#define CopyMarketDataBaseEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->PreSettlementPrice=(source)->PreSettlementPrice;	\
			(target)->PreClosePrice=(source)->PreClosePrice;	\
			(target)->PreOpenInterest=(source)->PreOpenInterest;	\
			(target)->PreDelta=(source)->PreDelta;	\

#endif
#ifndef CopyMarketDataStaticEntity
#define CopyMarketDataStaticEntity(target,source)	\
			(target)->OpenPrice=(source)->OpenPrice;	\
			(target)->HighestPrice=(source)->HighestPrice;	\
			(target)->LowestPrice=(source)->LowestPrice;	\
			(target)->ClosePrice=(source)->ClosePrice;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\
			(target)->SettlementPrice=(source)->SettlementPrice;	\
			(target)->CurrDelta=(source)->CurrDelta;	\

#endif
#ifndef CopyMarketDataLastMatchEntity
#define CopyMarketDataLastMatchEntity(target,source)	\
			(target)->LastPrice=(source)->LastPrice;	\
			(target)->Volume=(source)->Volume;	\
			(target)->Turnover=(source)->Turnover;	\
			(target)->OpenInterest=(source)->OpenInterest;	\

#endif
#ifndef CopyMarketDataBestPriceEntity
#define CopyMarketDataBestPriceEntity(target,source)	\
			(target)->BidPrice1=(source)->BidPrice1;	\
			(target)->BidVolume1=(source)->BidVolume1;	\
			(target)->AskPrice1=(source)->AskPrice1;	\
			(target)->AskVolume1=(source)->AskVolume1;	\

#endif
#ifndef CopyMarketDataBid23Entity
#define CopyMarketDataBid23Entity(target,source)	\
			(target)->BidPrice2=(source)->BidPrice2;	\
			(target)->BidVolume2=(source)->BidVolume2;	\
			(target)->BidPrice3=(source)->BidPrice3;	\
			(target)->BidVolume3=(source)->BidVolume3;	\

#endif
#ifndef CopyMarketDataAsk23Entity
#define CopyMarketDataAsk23Entity(target,source)	\
			(target)->AskPrice2=(source)->AskPrice2;	\
			(target)->AskVolume2=(source)->AskVolume2;	\
			(target)->AskPrice3=(source)->AskPrice3;	\
			(target)->AskVolume3=(source)->AskVolume3;	\

#endif
#ifndef CopyMarketDataBid45Entity
#define CopyMarketDataBid45Entity(target,source)	\
			(target)->BidPrice4=(source)->BidPrice4;	\
			(target)->BidVolume4=(source)->BidVolume4;	\
			(target)->BidPrice5=(source)->BidPrice5;	\
			(target)->BidVolume5=(source)->BidVolume5;	\

#endif
#ifndef CopyMarketDataAsk45Entity
#define CopyMarketDataAsk45Entity(target,source)	\
			(target)->AskPrice4=(source)->AskPrice4;	\
			(target)->AskVolume4=(source)->AskVolume4;	\
			(target)->AskPrice5=(source)->AskPrice5;	\
			(target)->AskVolume5=(source)->AskVolume5;	\

#endif
#ifndef CopyMarketDataUpdateTimeEntity
#define CopyMarketDataUpdateTimeEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->UpdateTime=(source)->UpdateTime;	\
			(target)->UpdateMillisec=(source)->UpdateMillisec;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyQryOrderV1Entity
#define CopyQryOrderV1Entity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyQryOrderEntity
#define CopyQryOrderEntity(target,source)	\
			CopyQryOrderV1Entity(target,source);	\
			(target)->TimeStart=(source)->TimeStart;	\
			(target)->TimeEnd=(source)->TimeEnd;	\

#endif
#ifndef CopyQryCombOrderEntity
#define CopyQryCombOrderEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->CombOrderSysID=(source)->CombOrderSysID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyQryQuoteEntity
#define CopyQryQuoteEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->QuoteSysID=(source)->QuoteSysID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyQryTradeV1Entity
#define CopyQryTradeV1Entity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\
			(target)->TradeID=(source)->TradeID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyQryTradeEntity
#define CopyQryTradeEntity(target,source)	\
			CopyQryTradeV1Entity(target,source);	\
			(target)->TimeStart=(source)->TimeStart;	\
			(target)->TimeEnd=(source)->TimeEnd;	\

#endif
#ifndef CopyQryMarketDataEntity
#define CopyQryMarketDataEntity(target,source)	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopyQryMBLMarketDataEntity
#define CopyQryMBLMarketDataEntity(target,source)	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\
			(target)->Direction=(source)->Direction;	\

#endif
#ifndef CopyQryClientEntity
#define CopyQryClientEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->ClientIDStart=(source)->ClientIDStart;	\
			(target)->ClientIDEnd=(source)->ClientIDEnd;	\

#endif
#ifndef CopyQryPartPositionEntity
#define CopyQryPartPositionEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\

#endif
#ifndef CopyQryClientPositionV1Entity
#define CopyQryClientPositionV1Entity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->ClientIDStart=(source)->ClientIDStart;	\
			(target)->ClientIDEnd=(source)->ClientIDEnd;	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\

#endif
#ifndef CopyQryClientPositionEntity
#define CopyQryClientPositionEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->ClientIDStart=(source)->ClientIDStart;	\
			(target)->ClientIDEnd=(source)->ClientIDEnd;	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\
			(target)->ClientType=(source)->ClientType;	\

#endif
#ifndef CopyQryPartAccountEntity
#define CopyQryPartAccountEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->AccountID=(source)->AccountID;	\

#endif
#ifndef CopyQryInstrumentEntity
#define CopyQryInstrumentEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\

#endif
#ifndef CopyQryInstrumentStatusEntity
#define CopyQryInstrumentStatusEntity(target,source)	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\

#endif
#ifndef CopyQrySGDataSyncStatusEntity
#define CopyQrySGDataSyncStatusEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\

#endif
#ifndef CopyQryUserSessionEntity
#define CopyQryUserSessionEntity(target,source)	\
			(target)->UserIDStart=(source)->UserIDStart;	\
			(target)->UserIDEnd=(source)->UserIDEnd;	\

#endif
#ifndef CopyQryUserEntity
#define CopyQryUserEntity(target,source)	\
			(target)->UserIDStart=(source)->UserIDStart;	\
			(target)->UserIDEnd=(source)->UserIDEnd;	\

#endif
#ifndef CopyQryBulletinEntity
#define CopyQryBulletinEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->MarketID=(source)->MarketID;	\
			(target)->BulletinID=(source)->BulletinID;	\
			(target)->NewsType=(source)->NewsType;	\
			(target)->NewsUrgency=(source)->NewsUrgency;	\

#endif
#ifndef CopyQryParticipantEntity
#define CopyQryParticipantEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\

#endif
#ifndef CopyQryHedgeVolumeEntity
#define CopyQryHedgeVolumeEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->ClientIDStart=(source)->ClientIDStart;	\
			(target)->ClientIDEnd=(source)->ClientIDEnd;	\
			(target)->InstIDStart=(source)->InstIDStart;	\
			(target)->InstIDEnd=(source)->InstIDEnd;	\

#endif
#ifndef CopyQryInformationEntity
#define CopyQryInformationEntity(target,source)	\
			(target)->InformationIDStart=(source)->InformationIDStart;	\
			(target)->InformationIDEnd=(source)->InformationIDEnd;	\

#endif
#ifndef CopyQryCreditLimitEntity
#define CopyQryCreditLimitEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\

#endif
#ifndef CopyQryExecOrderEntity
#define CopyQryExecOrderEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->ExecOrderSysID=(source)->ExecOrderSysID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->TimeStart=(source)->TimeStart;	\
			(target)->TimeEnd=(source)->TimeEnd;	\

#endif
#ifndef CopyQryAbandonExecOrderEntity
#define CopyQryAbandonExecOrderEntity(target,source)	\
			(target)->PartIDStart=(source)->PartIDStart;	\
			(target)->PartIDEnd=(source)->PartIDEnd;	\
			(target)->AbandonExecOrderSysID=(source)->AbandonExecOrderSysID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->TimeStart=(source)->TimeStart;	\
			(target)->TimeEnd=(source)->TimeEnd;	\

#endif
#ifndef CopyQryExchangeRateEntity
#define CopyQryExchangeRateEntity(target,source)	\
			(target)->CurrencyID=(source)->CurrencyID;	\

#endif
#ifndef CopyRspPartAccountEntity
#define CopyRspPartAccountEntity(target,source)	\
			CopyTradingAccountEntity(target,source);	\
			(target)->BaseReserve=(source)->BaseReserve;	\

#endif
#ifndef CopyRspPartPositionEntity
#define CopyRspPartPositionEntity(target,source)	\
			CopyPartPositionEntity(target,source);	\

#endif
#ifndef CopyRspClientPositionEntity
#define CopyRspClientPositionEntity(target,source)	\
			CopyClientPositionEntity(target,source);	\

#endif
#ifndef CopyRspClientEntity
#define CopyRspClientEntity(target,source)	\
			CopyClientEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\

#endif
#ifndef CopyRspInstrumentEntity
#define CopyRspInstrumentEntity(target,source)	\
			CopyTradingInstrumentV1Entity(target,source);	\
			CopyInstDynPropertyEntity(target,source);	\
			CopyInstTradingPropertyEntity(target,source);	\
			(target)->CurrencyID=(source)->CurrencyID;	\

#endif
#ifndef CopyRspExchangeRateEntity
#define CopyRspExchangeRateEntity(target,source)	\
			CopyExchangeRateEntity(target,source);	\

#endif
#ifndef CopyAdminOrderEntity
#define CopyAdminOrderEntity(target,source)	\
			CopyInputAdminOrderEntity(target,source);	\

#endif
#ifndef CopyInputAdminOrderEntity
#define CopyInputAdminOrderEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->AdminOrderCommand=(source)->AdminOrderCommand;	\
			(target)->ClearingPartID=(source)->ClearingPartID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->Amount=(source)->Amount;	\
			CopySettlementGroupRefEntity(target,source);	\

#endif
#ifndef CopyHisProductPropertyEntity
#define CopyHisProductPropertyEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyProductPropertyEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisInstrumentPropertyEntity
#define CopyHisInstrumentPropertyEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyInstrumentPropertyEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisInstrumentPropertyExEntity
#define CopyHisInstrumentPropertyExEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyInstrumentPropertyEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\
			CopyInstTradingPropertyEntity(target,source);	\

#endif
#ifndef CopyHisPriceBandingEntity
#define CopyHisPriceBandingEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrPriceBandingEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisPartPosiLimitEntity
#define CopyHisPartPosiLimitEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrPartPosiLimitEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisPartPosiLimitDetailEntity
#define CopyHisPartPosiLimitDetailEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrPartPosiLimitDetailEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisClientPosiLimitEntity
#define CopyHisClientPosiLimitEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrClientPosiLimitEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisClientPosiLimitDetailEntity
#define CopyHisClientPosiLimitDetailEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrClientPosiLimitDetailEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisSpecialPosiLimitEntity
#define CopyHisSpecialPosiLimitEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrSpecialPosiLimitEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisSpecialPosiLimitDetailEntity
#define CopyHisSpecialPosiLimitDetailEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrSpecialPosiLimitDetailEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisHedgeRuleEntity
#define CopyHisHedgeRuleEntity(target,source)	\
			CopyCurrHedgeRuleEntity(target,source);	\

#endif
#ifndef CopyHisTradingSegmentAttrEntity
#define CopyHisTradingSegmentAttrEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrTradingSegmentAttrEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef CopyHisFuseEntity
#define CopyHisFuseEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyCurrFuseEntity(target,source);	\
			(target)->SettlementID=(source)->SettlementID;	\

#endif
#ifndef Copyclient_positionEntity
#define Copyclient_positionEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->sbuy_amt=(source)->sbuy_amt;	\
			(target)->sbuy_sum=(source)->sbuy_sum;	\
			(target)->ssell_amt=(source)->ssell_amt;	\
			(target)->ssell_sum=(source)->ssell_sum;	\
			(target)->sboff_amt=(source)->sboff_amt;	\
			(target)->sboff_sum=(source)->sboff_sum;	\
			(target)->ssoff_amt=(source)->ssoff_amt;	\
			(target)->ssoff_sum=(source)->ssoff_sum;	\
			(target)->hbuy_amt=(source)->hbuy_amt;	\
			(target)->hbuy_sum=(source)->hbuy_sum;	\
			(target)->hsell_amt=(source)->hsell_amt;	\
			(target)->hsell_sum=(source)->hsell_sum;	\
			(target)->hboff_amt=(source)->hboff_amt;	\
			(target)->hboff_sum=(source)->hboff_sum;	\
			(target)->hsoff_amt=(source)->hsoff_amt;	\
			(target)->hsoff_sum=(source)->hsoff_sum;	\
			(target)->sbtotal_amt=(source)->sbtotal_amt;	\
			(target)->sbtotal_sum=(source)->sbtotal_sum;	\
			(target)->sstotal_amt=(source)->sstotal_amt;	\
			(target)->sstotal_sum=(source)->sstotal_sum;	\
			(target)->hbtotal_amt=(source)->hbtotal_amt;	\
			(target)->hbtotal_sum=(source)->hbtotal_sum;	\
			(target)->hstotal_amt=(source)->hstotal_amt;	\
			(target)->hstotal_sum=(source)->hstotal_sum;	\
			(target)->sbmargin=(source)->sbmargin;	\
			(target)->hbmargin=(source)->hbmargin;	\
			(target)->ssmargin=(source)->ssmargin;	\
			(target)->hsmargin=(source)->hsmargin;	\
			(target)->actual=(source)->actual;	\
			(target)->add_value=(source)->add_value;	\
			(target)->transfee=(source)->transfee;	\
			(target)->js_transfee=(source)->js_transfee;	\
			(target)->yc_transfee=(source)->yc_transfee;	\
			(target)->trans_tax=(source)->trans_tax;	\
			(target)->accountgl=(source)->accountgl;	\
			(target)->fxjj=(source)->fxjj;	\
			(target)->clearprice=(source)->clearprice;	\
			(target)->sbavg_pri=(source)->sbavg_pri;	\
			(target)->ssavg_pri=(source)->ssavg_pri;	\
			(target)->hbavg_pri=(source)->hbavg_pri;	\
			(target)->hsavg_pri=(source)->hsavg_pri;	\
			(target)->SLongMarginRatio=(source)->SLongMarginRatio;	\
			(target)->SShortMarginRatio=(source)->SShortMarginRatio;	\
			(target)->HLongMarginRatio=(source)->HLongMarginRatio;	\
			(target)->HShortMarginRatio=(source)->HShortMarginRatio;	\
			(target)->SLongMarginPrice=(source)->SLongMarginPrice;	\
			(target)->SShortMarginPrice=(source)->SShortMarginPrice;	\
			(target)->HLongMarginPrice=(source)->HLongMarginPrice;	\
			(target)->HShortMarginPrice=(source)->HShortMarginPrice;	\

#endif
#ifndef CopyClientOverLimitStatEntity
#define CopyClientOverLimitStatEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->TotalAmt=(source)->TotalAmt;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->StatType=(source)->StatType;	\
			(target)->ForceCloseType=(source)->ForceCloseType;	\
			(target)->LongPositionAmt=(source)->LongPositionAmt;	\
			(target)->LongForceCloseAmt=(source)->LongForceCloseAmt;	\
			(target)->LongForcedClosedAmt=(source)->LongForcedClosedAmt;	\
			(target)->ShortPositionAmt=(source)->ShortPositionAmt;	\
			(target)->ShortForceCloseAmt=(source)->ShortForceCloseAmt;	\
			(target)->ShortForceClosedAmt=(source)->ShortForceClosedAmt;	\
			(target)->ForceMoney=(source)->ForceMoney;	\
			(target)->ForcedMoney=(source)->ForcedMoney;	\
			(target)->ClientOverLimitCalcID=(source)->ClientOverLimitCalcID;	\
			(target)->Status=(source)->Status;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef Copyday_deliv_moneyEntity
#define Copyday_deliv_moneyEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->money_sum=(source)->money_sum;	\

#endif
#ifndef Copyday_deliv_transfeeEntity
#define Copyday_deliv_transfeeEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->money_sum=(source)->money_sum;	\

#endif
#ifndef Copyday_mortgage_money_sumEntity
#define Copyday_mortgage_money_sumEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->money_sum=(source)->money_sum;	\

#endif
#ifndef Copydeliv_transfeeEntity
#define Copydeliv_transfeeEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->OpSettlementID=(source)->OpSettlementID;	\
			(target)->cleardate=(source)->cleardate;	\
			(target)->delivdate=(source)->delivdate;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CommodityID=(source)->CommodityID;	\
			(target)->jgje=(source)->jgje;	\
			(target)->transfee=(source)->transfee;	\
			(target)->jgsl=(source)->jgsl;	\
			(target)->DeliveryMode=(source)->DeliveryMode;	\
			(target)->buytot=(source)->buytot;	\
			(target)->soldtot=(source)->soldtot;	\

#endif
#ifndef CopydyhzEntity
#define CopydyhzEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->je=(source)->je;	\
			(target)->sjje=(source)->sjje;	\
			(target)->type=(source)->type;	\

#endif
#ifndef CopyDBInstrumentPropertyEntity
#define CopyDBInstrumentPropertyEntity(target,source)	\
			CopyInstrumentPropertyEntity(target,source);	\
			CopyInstDynPropertyExprEntity(target,source);	\

#endif
#ifndef CopyjgycdzyEntity
#define CopyjgycdzyEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->amount=(source)->amount;	\
			(target)->bsflag=(source)->bsflag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef Copymember_clearEntity
#define Copymember_clearEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->sbuy_amt=(source)->sbuy_amt;	\
			(target)->sbuy_sum=(source)->sbuy_sum;	\
			(target)->ssell_amt=(source)->ssell_amt;	\
			(target)->ssell_sum=(source)->ssell_sum;	\
			(target)->sboff_amt=(source)->sboff_amt;	\
			(target)->sboff_sum=(source)->sboff_sum;	\
			(target)->ssoff_amt=(source)->ssoff_amt;	\
			(target)->ssoff_sum=(source)->ssoff_sum;	\
			(target)->hbuy_amt=(source)->hbuy_amt;	\
			(target)->hbuy_sum=(source)->hbuy_sum;	\
			(target)->hsell_amt=(source)->hsell_amt;	\
			(target)->hsell_sum=(source)->hsell_sum;	\
			(target)->hboff_amt=(source)->hboff_amt;	\
			(target)->hboff_sum=(source)->hboff_sum;	\
			(target)->hsoff_amt=(source)->hsoff_amt;	\
			(target)->hsoff_sum=(source)->hsoff_sum;	\
			(target)->sbtotal_amt=(source)->sbtotal_amt;	\
			(target)->sbtotal_sum=(source)->sbtotal_sum;	\
			(target)->sstotal_amt=(source)->sstotal_amt;	\
			(target)->sstotal_sum=(source)->sstotal_sum;	\
			(target)->hbtotal_amt=(source)->hbtotal_amt;	\
			(target)->hbtotal_sum=(source)->hbtotal_sum;	\
			(target)->hstotal_amt=(source)->hstotal_amt;	\
			(target)->hstotal_sum=(source)->hstotal_sum;	\
			(target)->sbavg_pri=(source)->sbavg_pri;	\
			(target)->ssavg_pri=(source)->ssavg_pri;	\
			(target)->hbavg_pri=(source)->hbavg_pri;	\
			(target)->hsavg_pri=(source)->hsavg_pri;	\
			(target)->actual=(source)->actual;	\
			(target)->add_value=(source)->add_value;	\
			(target)->transfee=(source)->transfee;	\
			(target)->js_transfee=(source)->js_transfee;	\
			(target)->yc_transfee=(source)->yc_transfee;	\
			(target)->trans_tax=(source)->trans_tax;	\
			(target)->smargin=(source)->smargin;	\
			(target)->hmargin=(source)->hmargin;	\
			(target)->accountgl=(source)->accountgl;	\
			(target)->clearprice=(source)->clearprice;	\
			(target)->fxjj=(source)->fxjj;	\

#endif
#ifndef Copymoney_ioEntity
#define Copymoney_ioEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->OpSettlementID=(source)->OpSettlementID;	\
			(target)->tradedate=(source)->tradedate;	\
			(target)->operationID=(source)->operationID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->zj_type_id=(source)->zj_type_id;	\
			(target)->income=(source)->income;	\
			(target)->goout=(source)->goout;	\
			(target)->bank_id=(source)->bank_id;	\
			(target)->remark=(source)->remark;	\
			(target)->trans_type=(source)->trans_type;	\
			(target)->bz=(source)->bz;	\
			(target)->tpbz=(source)->tpbz;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\

#endif
#ifndef CopyNotMultipleStatEntity
#define CopyNotMultipleStatEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->TotalAmt=(source)->TotalAmt;	\
			(target)->StatType=(source)->StatType;	\
			(target)->ForceCloseType=(source)->ForceCloseType;	\
			(target)->LongPositionAmt=(source)->LongPositionAmt;	\
			(target)->LongForceCloseAmt=(source)->LongForceCloseAmt;	\
			(target)->ShortPositionAmt=(source)->ShortPositionAmt;	\
			(target)->ShortForceCloseAmt=(source)->ShortForceCloseAmt;	\
			(target)->ForceMoney=(source)->ForceMoney;	\
			(target)->ForcedMoney=(source)->ForcedMoney;	\
			(target)->Status=(source)->Status;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartLackDepositStatEntity
#define CopyPartLackDepositStatEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->StatType=(source)->StatType;	\
			(target)->ForceCloseType=(source)->ForceCloseType;	\
			(target)->remain=(source)->remain;	\
			(target)->ForceMoney=(source)->ForceMoney;	\
			(target)->ForcedMoney=(source)->ForcedMoney;	\
			(target)->Status=(source)->Status;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartOverLimitStatEntity
#define CopyPartOverLimitStatEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->StatType=(source)->StatType;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->TotalAmt=(source)->TotalAmt;	\
			(target)->ForceCloseType=(source)->ForceCloseType;	\
			(target)->LongPositionAmt=(source)->LongPositionAmt;	\
			(target)->LongForceCloseAmt=(source)->LongForceCloseAmt;	\
			(target)->LongForcedClosedAmt=(source)->LongForcedClosedAmt;	\
			(target)->ShortPositionAmt=(source)->ShortPositionAmt;	\
			(target)->ShortForceCloseAmt=(source)->ShortForceCloseAmt;	\
			(target)->ShortForceClosedAmt=(source)->ShortForceClosedAmt;	\
			(target)->ForceMoney=(source)->ForceMoney;	\
			(target)->ForcedMoney=(source)->ForcedMoney;	\
			(target)->PartOverLimitCalcID=(source)->PartOverLimitCalcID;	\
			(target)->Status=(source)->Status;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartRoleAccEntity
#define CopyPartRoleAccEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef Copytransfee_derate_mxEntity
#define Copytransfee_derate_mxEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->due_transfee=(source)->due_transfee;	\
			(target)->hand_derate1=(source)->hand_derate1;	\
			(target)->hand_derate2=(source)->hand_derate2;	\
			(target)->hand_derate3=(source)->hand_derate3;	\
			(target)->compare_derate=(source)->compare_derate;	\
			(target)->offset_derate=(source)->offset_derate;	\
			(target)->client_derate=(source)->client_derate;	\
			(target)->fact_transfee=(source)->fact_transfee;	\

#endif
#ifndef CopyzdhzkEntity
#define CopyzdhzkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CommodityID=(source)->CommodityID;	\
			(target)->tdprice=(source)->tdprice;	\
			(target)->zdw=(source)->zdw;	\
			(target)->zje=(source)->zje;	\
			(target)->zkje=(source)->zkje;	\
			(target)->tpdyje=(source)->tpdyje;	\
			(target)->tpsjje=(source)->tpsjje;	\
			(target)->tpzyje=(source)->tpzyje;	\

#endif
#ifndef Copyzj_clearEntity
#define Copyzj_clearEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->init_margin=(source)->init_margin;	\
			(target)->jg_margin=(source)->jg_margin;	\
			(target)->actual=(source)->actual;	\
			(target)->add_value=(source)->add_value;	\
			(target)->transfee=(source)->transfee;	\
			(target)->js_transfee=(source)->js_transfee;	\
			(target)->yc_transfee=(source)->yc_transfee;	\
			(target)->trans_tax=(source)->trans_tax;	\
			(target)->smargin=(source)->smargin;	\
			(target)->hmargin=(source)->hmargin;	\
			(target)->mortgage_i=(source)->mortgage_i;	\
			(target)->mortgage_o=(source)->mortgage_o;	\
			(target)->mortgage=(source)->mortgage;	\
			(target)->real_mortgage=(source)->real_mortgage;	\
			(target)->money_i=(source)->money_i;	\
			(target)->money_o=(source)->money_o;	\
			(target)->deposit=(source)->deposit;	\
			(target)->remain=(source)->remain;	\
			(target)->prepa=(source)->prepa;	\
			(target)->ldeposit=(source)->ldeposit;	\
			(target)->tkxe=(source)->tkxe;	\
			(target)->fxbz=(source)->fxbz;	\
			(target)->pzhk=(source)->pzhk;	\
			(target)->AccountStatus=(source)->AccountStatus;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->CloseDate=(source)->CloseDate;	\

#endif
#ifndef Copyzj_typeEntity
#define Copyzj_typeEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->zj_type_id=(source)->zj_type_id;	\
			(target)->name=(source)->name;	\
			(target)->confirm_flag=(source)->confirm_flag;	\
			(target)->in_margin_flag=(source)->in_margin_flag;	\
			(target)->MoneyTransFlag=(source)->MoneyTransFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef Copyzj_type_checkEntity
#define Copyzj_type_checkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->zj_type_id=(source)->zj_type_id;	\
			(target)->name=(source)->name;	\
			(target)->confirm_flag=(source)->confirm_flag;	\
			(target)->in_margin_flag=(source)->in_margin_flag;	\
			(target)->MoneyTransFlag=(source)->MoneyTransFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->op_type=(source)->op_type;	\

#endif
#ifndef CopyMemberExEntity
#define CopyMemberExEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->mortgage_rate_off=(source)->mortgage_rate_off;	\
			(target)->cke_rate=(source)->cke_rate;	\
			(target)->fxbz=(source)->fxbz;	\
			(target)->base_margi=(source)->base_margi;	\
			(target)->bank_id=(source)->bank_id;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef Copymember_interestEntity
#define Copymember_interestEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->begin_date=(source)->begin_date;	\
			(target)->end_date=(source)->end_date;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->base=(source)->base;	\
			(target)->interest=(source)->interest;	\
			(target)->profit=(source)->profit;	\
			(target)->adjust=(source)->adjust;	\
			(target)->real_profit=(source)->real_profit;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->OperationID=(source)->OperationID;	\

#endif
#ifndef CopyAccountPropertyEntity
#define CopyAccountPropertyEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->AccountName=(source)->AccountName;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyCPTChangeDetailEntity
#define CopyCPTChangeDetailEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->LongTransVolume=(source)->LongTransVolume;	\
			(target)->ShortTransVolume=(source)->ShortTransVolume;	\
			(target)->MarginChange=(source)->MarginChange;	\

#endif
#ifndef CopyClientPosTransferEntity
#define CopyClientPosTransferEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->OutTradingPartID=(source)->OutTradingPartID;	\
			(target)->OutSettlePartID=(source)->OutSettlePartID;	\
			(target)->OutAccountID=(source)->OutAccountID;	\
			(target)->InTradingPartID=(source)->InTradingPartID;	\
			(target)->InSettlePartID=(source)->InSettlePartID;	\
			(target)->InAccountID=(source)->InAccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->CompleteFlag=(source)->CompleteFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\

#endif
#ifndef CopyPPTChangeDetailEntity
#define CopyPPTChangeDetailEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->LongTransVolume=(source)->LongTransVolume;	\
			(target)->ShortTransVolume=(source)->ShortTransVolume;	\
			(target)->MarginChange=(source)->MarginChange;	\

#endif
#ifndef CopyPartPosTransferEntity
#define CopyPartPosTransferEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->TradingPartID=(source)->TradingPartID;	\
			(target)->OutSettlePartID=(source)->OutSettlePartID;	\
			(target)->OutAccountID=(source)->OutAccountID;	\
			(target)->InSettlePartID=(source)->InSettlePartID;	\
			(target)->InAccountID=(source)->InAccountID;	\
			(target)->CompleteFlag=(source)->CompleteFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\

#endif
#ifndef CopyHedgeChangeResultEntity
#define CopyHedgeChangeResultEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->HedgeQuotaSN=(source)->HedgeQuotaSN;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->LongPosition=(source)->LongPosition;	\
			(target)->ShortPosition=(source)->ShortPosition;	\
			(target)->HedgeLongPosition=(source)->HedgeLongPosition;	\
			(target)->HedgeShortPosition=(source)->HedgeShortPosition;	\
			(target)->SettlementPrice=(source)->SettlementPrice;	\

#endif
#ifndef Copyday_mortgage_money_sum_newEntity
#define Copyday_mortgage_money_sum_newEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->money_sum=(source)->money_sum;	\
			(target)->CommodityID=(source)->CommodityID;	\

#endif
#ifndef CopyForceDealEntity
#define CopyForceDealEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->TradeID=(source)->TradeID;	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->OffsetFlag=(source)->OffsetFlag;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->Price=(source)->Price;	\
			(target)->Volume=(source)->Volume;	\
			(target)->Tradetype=(source)->Tradetype;	\
			(target)->LastClearPrice=(source)->LastClearPrice;	\
			(target)->Actual=(source)->Actual;	\

#endif
#ifndef CopyMarginRateChangeDetailEntity
#define CopyMarginRateChangeDetailEntity(target,source)	\
			(target)->id=(source)->id;	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongMarginRatio=(source)->LongMarginRatio;	\
			(target)->ShortMarginRatio=(source)->ShortMarginRatio;	\
			(target)->ChangeReason=(source)->ChangeReason;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartRoleAcc_checkEntity
#define CopyPartRoleAcc_checkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->op_type=(source)->op_type;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef Copyzj_clear_checkEntity
#define Copyzj_clear_checkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->init_margin=(source)->init_margin;	\
			(target)->jg_margin=(source)->jg_margin;	\
			(target)->actual=(source)->actual;	\
			(target)->add_value=(source)->add_value;	\
			(target)->transfee=(source)->transfee;	\
			(target)->js_transfee=(source)->js_transfee;	\
			(target)->yc_transfee=(source)->yc_transfee;	\
			(target)->trans_tax=(source)->trans_tax;	\
			(target)->smargin=(source)->smargin;	\
			(target)->hmargin=(source)->hmargin;	\
			(target)->mortgage_i=(source)->mortgage_i;	\
			(target)->mortgage_o=(source)->mortgage_o;	\
			(target)->mortgage=(source)->mortgage;	\
			(target)->real_mortgage=(source)->real_mortgage;	\
			(target)->money_i=(source)->money_i;	\
			(target)->money_o=(source)->money_o;	\
			(target)->deposit=(source)->deposit;	\
			(target)->remain=(source)->remain;	\
			(target)->prepa=(source)->prepa;	\
			(target)->ldeposit=(source)->ldeposit;	\
			(target)->tkxe=(source)->tkxe;	\
			(target)->fxbz=(source)->fxbz;	\
			(target)->pzhk=(source)->pzhk;	\
			(target)->AccountStatus=(source)->AccountStatus;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->CloseDate=(source)->CloseDate;	\
			(target)->op_type=(source)->op_type;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyTransfeeDerateLimit_checkEntity
#define CopyTransfeeDerateLimit_checkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CommodityID=(source)->CommodityID;	\
			(target)->DerateAmountOriginal=(source)->DerateAmountOriginal;	\
			(target)->DerateAmount=(source)->DerateAmount;	\
			(target)->EffectDate=(source)->EffectDate;	\
			(target)->op_type=(source)->op_type;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartChangeTransferEntity
#define CopyPartChangeTransferEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->OutPartID=(source)->OutPartID;	\
			(target)->OutSettlePartID=(source)->OutSettlePartID;	\
			(target)->OutAccountID=(source)->OutAccountID;	\
			(target)->InPartID=(source)->InPartID;	\
			(target)->InSettlePartID=(source)->InSettlePartID;	\
			(target)->InAccountID=(source)->InAccountID;	\
			(target)->CompleteFlag=(source)->CompleteFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\

#endif
#ifndef CopyPartChangeTransfer_checkEntity
#define CopyPartChangeTransfer_checkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->OutPartID=(source)->OutPartID;	\
			(target)->OutSettlePartID=(source)->OutSettlePartID;	\
			(target)->OutAccountID=(source)->OutAccountID;	\
			(target)->InPartID=(source)->InPartID;	\
			(target)->InSettlePartID=(source)->InSettlePartID;	\
			(target)->InAccountID=(source)->InAccountID;	\
			(target)->CompleteFlag=(source)->CompleteFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\
			(target)->CheckOpType=(source)->CheckOpType;	\

#endif
#ifndef CopyPCTChangeDetailEntity
#define CopyPCTChangeDetailEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->LongTransVolume=(source)->LongTransVolume;	\
			(target)->ShortTransVolume=(source)->ShortTransVolume;	\
			(target)->MarginChange=(source)->MarginChange;	\

#endif
#ifndef CopyPCTClientDetailEntity
#define CopyPCTClientDetailEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->ClientType=(source)->ClientType;	\

#endif
#ifndef CopyPartSettleDaySumEntity
#define CopyPartSettleDaySumEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->buy_amt=(source)->buy_amt;	\
			(target)->sell_amt=(source)->sell_amt;	\
			(target)->BuyOpenAmt=(source)->BuyOpenAmt;	\
			(target)->SellOpenAmt=(source)->SellOpenAmt;	\
			(target)->boff_amt=(source)->boff_amt;	\
			(target)->soff_amt=(source)->soff_amt;	\
			(target)->sbtotal_amt=(source)->sbtotal_amt;	\
			(target)->sstotal_amt=(source)->sstotal_amt;	\
			(target)->hbtotal_amt=(source)->hbtotal_amt;	\
			(target)->hstotal_amt=(source)->hstotal_amt;	\
			(target)->buy_sum=(source)->buy_sum;	\
			(target)->sell_sum=(source)->sell_sum;	\
			(target)->btotal_sum=(source)->btotal_sum;	\
			(target)->stotal_sum=(source)->stotal_sum;	\
			(target)->jymargin=(source)->jymargin;	\
			(target)->actual=(source)->actual;	\
			(target)->jytransfee=(source)->jytransfee;	\
			(target)->trans_tax=(source)->trans_tax;	\
			(target)->yctransfee=(source)->yctransfee;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartStdInstSettleEntity
#define CopyPartStdInstSettleEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->SettlePartID=(source)->SettlePartID;	\
			(target)->SettlePartAbbr=(source)->SettlePartAbbr;	\
			(target)->ParticipantType=(source)->ParticipantType;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->clearprice=(source)->clearprice;	\
			(target)->sbuy_amt=(source)->sbuy_amt;	\
			(target)->sbuy_sum=(source)->sbuy_sum;	\
			(target)->ssell_amt=(source)->ssell_amt;	\
			(target)->ssell_sum=(source)->ssell_sum;	\
			(target)->sboff_amt=(source)->sboff_amt;	\
			(target)->sboff_sum=(source)->sboff_sum;	\
			(target)->ssoff_amt=(source)->ssoff_amt;	\
			(target)->ssoff_sum=(source)->ssoff_sum;	\
			(target)->sbtotal_amt=(source)->sbtotal_amt;	\
			(target)->sbtotal_sum=(source)->sbtotal_sum;	\
			(target)->sstotal_amt=(source)->sstotal_amt;	\
			(target)->sstotal_sum=(source)->sstotal_sum;	\
			(target)->hbuy_amt=(source)->hbuy_amt;	\
			(target)->hbuy_sum=(source)->hbuy_sum;	\
			(target)->hsell_amt=(source)->hsell_amt;	\
			(target)->hsell_sum=(source)->hsell_sum;	\
			(target)->hboff_amt=(source)->hboff_amt;	\
			(target)->hboff_sum=(source)->hboff_sum;	\
			(target)->hsoff_amt=(source)->hsoff_amt;	\
			(target)->hsoff_sum=(source)->hsoff_sum;	\
			(target)->hbtotal_amt=(source)->hbtotal_amt;	\
			(target)->hbtotal_sum=(source)->hbtotal_sum;	\
			(target)->hstotal_amt=(source)->hstotal_amt;	\
			(target)->hstotal_sum=(source)->hstotal_sum;	\
			(target)->shmargin=(source)->shmargin;	\
			(target)->actual=(source)->actual;	\
			(target)->transfee=(source)->transfee;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyTradeVarietySumEntity
#define CopyTradeVarietySumEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClearPrice=(source)->ClearPrice;	\
			(target)->UpPrice=(source)->UpPrice;	\
			(target)->BuyAmt=(source)->BuyAmt;	\
			(target)->SellAmt=(source)->SellAmt;	\
			(target)->BOpenAmt=(source)->BOpenAmt;	\
			(target)->SOpenAmt=(source)->SOpenAmt;	\
			(target)->BOffAmt=(source)->BOffAmt;	\
			(target)->SOffAmt=(source)->SOffAmt;	\
			(target)->BuyDelivAmt=(source)->BuyDelivAmt;	\
			(target)->SellDelivAmt=(source)->SellDelivAmt;	\
			(target)->BTotalAmt=(source)->BTotalAmt;	\
			(target)->STotalAmt=(source)->STotalAmt;	\
			(target)->BuySum=(source)->BuySum;	\
			(target)->SellSum=(source)->SellSum;	\
			(target)->BTotalSum=(source)->BTotalSum;	\
			(target)->STotalSum=(source)->STotalSum;	\
			(target)->BAIL=(source)->BAIL;	\
			(target)->Actual=(source)->Actual;	\
			(target)->Transfee=(source)->Transfee;	\
			(target)->JSTransfee=(source)->JSTransfee;	\
			(target)->TransTax=(source)->TransTax;	\
			(target)->YCTransfee=(source)->YCTransfee;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyPartMoneyDaySumEntity
#define CopyPartMoneyDaySumEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->ldeposit=(source)->ldeposit;	\
			(target)->money_i=(source)->money_i;	\
			(target)->money_o=(source)->money_o;	\
			(target)->TotalTransfee=(source)->TotalTransfee;	\
			(target)->actual=(source)->actual;	\
			(target)->init_margin=(source)->init_margin;	\
			(target)->remain=(source)->remain;	\
			(target)->deposit=(source)->deposit;	\
			(target)->mortgage=(source)->mortgage;	\
			(target)->tkxe=(source)->tkxe;	\
			(target)->prepa=(source)->prepa;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyBillSequenceNoEntity
#define CopyBillSequenceNoEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->MoneyTypeID=(source)->MoneyTypeID;	\
			(target)->MoneyTypeName=(source)->MoneyTypeName;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyClearingParticipantEntity
#define CopyClearingParticipantEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->ClearPartName=(source)->ClearPartName;	\
			(target)->ClearPartAbbr=(source)->ClearPartAbbr;	\
			(target)->ClearPartProperty=(source)->ClearPartProperty;	\
			(target)->ClearPartType=(source)->ClearPartType;	\
			(target)->OtherSystemID=(source)->OtherSystemID;	\
			(target)->ClearPartStatus=(source)->ClearPartStatus;	\
			(target)->OpenOperatorID=(source)->OpenOperatorID;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->OpenTime=(source)->OpenTime;	\
			(target)->OpenCheckerID=(source)->OpenCheckerID;	\
			(target)->OpenCheckDate=(source)->OpenCheckDate;	\
			(target)->OpenCheckTime=(source)->OpenCheckTime;	\
			(target)->CloseOperatorID=(source)->CloseOperatorID;	\
			(target)->CloseDate=(source)->CloseDate;	\
			(target)->CloseTime=(source)->CloseTime;	\
			(target)->CloseCheckerID=(source)->CloseCheckerID;	\
			(target)->CloseCheckDate=(source)->CloseCheckDate;	\
			(target)->CloseCheckTime=(source)->CloseCheckTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef CopyClearPartAccountEntity
#define CopyClearPartAccountEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->AccountStatus=(source)->AccountStatus;	\
			(target)->OpenOperatorID=(source)->OpenOperatorID;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->OpenTime=(source)->OpenTime;	\
			(target)->OpenCheckerID=(source)->OpenCheckerID;	\
			(target)->OpenCheckDate=(source)->OpenCheckDate;	\
			(target)->OpenCheckTime=(source)->OpenCheckTime;	\
			(target)->CloseOperatorID=(source)->CloseOperatorID;	\
			(target)->CloseDate=(source)->CloseDate;	\
			(target)->CloseTime=(source)->CloseTime;	\
			(target)->CloseCheckerID=(source)->CloseCheckerID;	\
			(target)->CloseCheckDate=(source)->CloseCheckDate;	\
			(target)->CloseCheckTime=(source)->CloseCheckTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef CopyClearPartBankAccountEntity
#define CopyClearPartBankAccountEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->BankID=(source)->BankID;	\
			(target)->OpenBankCode=(source)->OpenBankCode;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->BankAcctName=(source)->BankAcctName;	\
			(target)->BankAccPriority=(source)->BankAccPriority;	\
			(target)->BankAccProperty=(source)->BankAccProperty;	\
			(target)->BankAcctType=(source)->BankAcctType;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef CopyClearingPartCheckEntity
#define CopyClearingPartCheckEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->ClearPartName=(source)->ClearPartName;	\
			(target)->ClearPartAbbr=(source)->ClearPartAbbr;	\
			(target)->ClearPartProperty=(source)->ClearPartProperty;	\
			(target)->ClearPartType=(source)->ClearPartType;	\
			(target)->OtherSystemID=(source)->OtherSystemID;	\
			(target)->ClearPartStatus=(source)->ClearPartStatus;	\
			(target)->OpenOperatorID=(source)->OpenOperatorID;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->OpenTime=(source)->OpenTime;	\
			(target)->CloseOperatorID=(source)->CloseOperatorID;	\
			(target)->CloseDate=(source)->CloseDate;	\
			(target)->CloseTime=(source)->CloseTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckOpType=(source)->CheckOpType;	\

#endif
#ifndef CopyClearPartAccountCheckEntity
#define CopyClearPartAccountCheckEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->AccountStatus=(source)->AccountStatus;	\
			(target)->OpenOperatorID=(source)->OpenOperatorID;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->OpenTime=(source)->OpenTime;	\
			(target)->CloseOperatorID=(source)->CloseOperatorID;	\
			(target)->CloseDate=(source)->CloseDate;	\
			(target)->CloseTime=(source)->CloseTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckOpType=(source)->CheckOpType;	\

#endif
#ifndef CopyClearPartBankAccCheckEntity
#define CopyClearPartBankAccCheckEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->BankID=(source)->BankID;	\
			(target)->OpenBankCode=(source)->OpenBankCode;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->BankAcctName=(source)->BankAcctName;	\
			(target)->BankAccPriority=(source)->BankAccPriority;	\
			(target)->BankAccProperty=(source)->BankAccProperty;	\
			(target)->BankAcctType=(source)->BankAcctType;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckOpType=(source)->CheckOpType;	\

#endif
#ifndef CopyClearPartMoneyIODelLogEntity
#define CopyClearPartMoneyIODelLogEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->id=(source)->id;	\
			(target)->TradeDate=(source)->TradeDate;	\
			(target)->OperationID=(source)->OperationID;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->BankID=(source)->BankID;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->MoneyTypeID=(source)->MoneyTypeID;	\
			(target)->Income=(source)->Income;	\
			(target)->Goout=(source)->Goout;	\
			(target)->TransType=(source)->TransType;	\
			(target)->ConfirmFlag=(source)->ConfirmFlag;	\
			(target)->WithdrawFlag=(source)->WithdrawFlag;	\
			(target)->Remark=(source)->Remark;	\
			(target)->IsDel=(source)->IsDel;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\
			(target)->DelOperatorID=(source)->DelOperatorID;	\
			(target)->DelOpDate=(source)->DelOpDate;	\
			(target)->DelOpTime=(source)->DelOpTime;	\
			(target)->DelCheckerID=(source)->DelCheckerID;	\
			(target)->DelCheckDate=(source)->DelCheckDate;	\
			(target)->DelCheckTime=(source)->DelCheckTime;	\

#endif
#ifndef CopyClearPriceLogEntity
#define CopyClearPriceLogEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->TaskID=(source)->TaskID;	\
			(target)->TaskName=(source)->TaskName;	\
			(target)->OpType=(source)->OpType;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->clearprice=(source)->clearprice;	\
			(target)->lastprice=(source)->lastprice;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyFormalClearLogEntity
#define CopyFormalClearLogEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClearNo=(source)->ClearNo;	\
			(target)->TaskID=(source)->TaskID;	\
			(target)->TaskName=(source)->TaskName;	\
			(target)->BeginTime=(source)->BeginTime;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->LogInfo=(source)->LogInfo;	\

#endif
#ifndef CopyFinancialFeeEntity
#define CopyFinancialFeeEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->MoneyTypeID=(source)->MoneyTypeID;	\
			(target)->MoneyTypeName=(source)->MoneyTypeName;	\
			(target)->FeeMoney=(source)->FeeMoney;	\
			(target)->AvailableMoney=(source)->AvailableMoney;	\
			(target)->VerifyStatus=(source)->VerifyStatus;	\
			(target)->FirstOpResult=(source)->FirstOpResult;	\
			(target)->SecondOpResult=(source)->SecondOpResult;	\
			(target)->MoneyIOBillNo=(source)->MoneyIOBillNo;	\
			(target)->FinancialOpName=(source)->FinancialOpName;	\
			(target)->InputorID=(source)->InputorID;	\
			(target)->InputDate=(source)->InputDate;	\
			(target)->InputTime=(source)->InputTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef CopyClearPartMoneyIOEntity
#define CopyClearPartMoneyIOEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->TradeDate=(source)->TradeDate;	\
			(target)->OperationID=(source)->OperationID;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->BankID=(source)->BankID;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->MoneyTypeID=(source)->MoneyTypeID;	\
			(target)->Income=(source)->Income;	\
			(target)->Goout=(source)->Goout;	\
			(target)->TransType=(source)->TransType;	\
			(target)->ConfirmFlag=(source)->ConfirmFlag;	\
			(target)->WithdrawFlag=(source)->WithdrawFlag;	\
			(target)->Remark=(source)->Remark;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ConfirmerID=(source)->ConfirmerID;	\
			(target)->ConfirmDate=(source)->ConfirmDate;	\
			(target)->ConfirmTime=(source)->ConfirmTime;	\

#endif
#ifndef CopyClearPartMoneyIO_checkEntity
#define CopyClearPartMoneyIO_checkEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ID=(source)->ID;	\
			(target)->TradeDate=(source)->TradeDate;	\
			(target)->OperationID=(source)->OperationID;	\
			(target)->ClearPartID=(source)->ClearPartID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->BankID=(source)->BankID;	\
			(target)->BankAccount=(source)->BankAccount;	\
			(target)->MoneyTypeID=(source)->MoneyTypeID;	\
			(target)->Income=(source)->Income;	\
			(target)->Goout=(source)->Goout;	\
			(target)->TransType=(source)->TransType;	\
			(target)->Remark=(source)->Remark;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyClearPartTypeEntity
#define CopyClearPartTypeEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClearPartType=(source)->ClearPartType;	\
			(target)->ClearPartTypeName=(source)->ClearPartTypeName;	\
			(target)->ClearPartProperty=(source)->ClearPartProperty;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyClientTaxInfoEntity
#define CopyClientTaxInfoEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->TaxID=(source)->TaxID;	\
			(target)->AddressInfo=(source)->AddressInfo;	\
			(target)->BankInfo=(source)->BankInfo;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\

#endif
#ifndef CopyClientTaxInfoCheckEntity
#define CopyClientTaxInfoCheckEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->CheckOpType=(source)->CheckOpType;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->TaxID=(source)->TaxID;	\
			(target)->AddressInfo=(source)->AddressInfo;	\
			(target)->BankInfo=(source)->BankInfo;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyOosSettlementAddTaxEntity
#define CopyOosSettlementAddTaxEntity(target,source)	\
			(target)->OosSettId=(source)->OosSettId;	\
			(target)->VarId=(source)->VarId;	\
			(target)->SettDate=(source)->SettDate;	\
			(target)->SettType=(source)->SettType;	\
			(target)->BusinessPaperId=(source)->BusinessPaperId;	\
			(target)->WhId=(source)->WhId;	\
			(target)->MemId=(source)->MemId;	\
			(target)->MemAbbr=(source)->MemAbbr;	\
			(target)->CltId=(source)->CltId;	\
			(target)->CltName=(source)->CltName;	\
			(target)->Quality=(source)->Quality;	\
			(target)->StandardWght=(source)->StandardWght;	\
			(target)->GrossWght=(source)->GrossWght;	\
			(target)->Wght=(source)->Wght;	\
			(target)->OosWght=(source)->OosWght;	\
			(target)->SettPrice=(source)->SettPrice;	\
			(target)->SettSum=(source)->SettSum;	\
			(target)->AppDate=(source)->AppDate;	\
			(target)->CofDate=(source)->CofDate;	\
			(target)->OosSettStat=(source)->OosSettStat;	\
			(target)->RefRsn=(source)->RefRsn;	\
			(target)->Remk=(source)->Remk;	\
			(target)->TotalAmt=(source)->TotalAmt;	\
			(target)->Price=(source)->Price;	\
			(target)->TotalSum=(source)->TotalSum;	\

#endif
#ifndef CopyClientDelivOutEntity
#define CopyClientDelivOutEntity(target,source)	\
			(target)->TradeDate=(source)->TradeDate;	\
			(target)->DelivDate=(source)->DelivDate;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->DelivPrice=(source)->DelivPrice;	\
			(target)->LongVolume=(source)->LongVolume;	\
			(target)->ShortVolume=(source)->ShortVolume;	\
			(target)->TotalVolume=(source)->TotalVolume;	\
			(target)->NotOutVolume=(source)->NotOutVolume;	\
			(target)->Transfee=(source)->Transfee;	\

#endif
#ifndef CopySyncWarrantFileEntity
#define CopySyncWarrantFileEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->MemId=(source)->MemId;	\
			(target)->CltId=(source)->CltId;	\
			(target)->VarId=(source)->VarId;	\
			(target)->WhId=(source)->WhId;	\
			(target)->WrtVol=(source)->WrtVol;	\

#endif
#ifndef CopySyncWarehouseFileEntity
#define CopySyncWarehouseFileEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->WhId=(source)->WhId;	\
			(target)->WhName=(source)->WhName;	\
			(target)->VarId=(source)->VarId;	\
			(target)->Stock=(source)->Stock;	\
			(target)->Ratcap=(source)->Ratcap;	\

#endif
#ifndef CopyMemberHandDerateLogEntity
#define CopyMemberHandDerateLogEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->SequenceNo =(source)->SequenceNo ;	\
			(target)->TaskID=(source)->TaskID;	\
			(target)->TaskName=(source)->TaskName;	\
			(target)->TotRecord =(source)->TotRecord ;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyFinancialFeeReturnEntity
#define CopyFinancialFeeReturnEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ID=(source)->ID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->AccountProperty=(source)->AccountProperty;	\
			(target)->MoneyTypeID=(source)->MoneyTypeID;	\
			(target)->MoneyTypeName=(source)->MoneyTypeName;	\
			(target)->FeeMoney=(source)->FeeMoney;	\
			(target)->AvailableMoney=(source)->AvailableMoney;	\
			(target)->VerifyStatus=(source)->VerifyStatus;	\
			(target)->ReturnStatus=(source)->ReturnStatus;	\
			(target)->FirstOpResult=(source)->FirstOpResult;	\
			(target)->SecondOpResult=(source)->SecondOpResult;	\
			(target)->MoneyIOBillNo=(source)->MoneyIOBillNo;	\
			(target)->FinancialOpName=(source)->FinancialOpName;	\
			(target)->InputorID=(source)->InputorID;	\
			(target)->InputDate=(source)->InputDate;	\
			(target)->InputTime=(source)->InputTime;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\
			(target)->CheckerID=(source)->CheckerID;	\
			(target)->CheckDate=(source)->CheckDate;	\
			(target)->CheckTime=(source)->CheckTime;	\
			(target)->ReturnerID=(source)->ReturnerID;	\
			(target)->ReturnDate=(source)->ReturnDate;	\
			(target)->ReturnTime=(source)->ReturnTime;	\
			(target)->ReturnCheckerID=(source)->ReturnCheckerID;	\
			(target)->ReturnCheckDate=(source)->ReturnCheckDate;	\
			(target)->ReturnCheckTime=(source)->ReturnCheckTime;	\

#endif
#ifndef CopyClientDelivProfitEntity
#define CopyClientDelivProfitEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->DelivMonth=(source)->DelivMonth;	\
			(target)->CommodityID=(source)->CommodityID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->DelivVolume=(source)->DelivVolume;	\
			(target)->ClearPrice=(source)->ClearPrice;	\
			(target)->DelivPrice=(source)->DelivPrice;	\
			(target)->DelivProfit=(source)->DelivProfit;	\
			(target)->AutoTransFlag=(source)->AutoTransFlag;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyClientDelivContractEntity
#define CopyClientDelivContractEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->DelivDate=(source)->DelivDate;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->TradeID=(source)->TradeID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->DelivVolume=(source)->DelivVolume;	\
			(target)->DelivMargin=(source)->DelivMargin;	\
			(target)->OpenPrice=(source)->OpenPrice;	\
			(target)->DelivPrice=(source)->DelivPrice;	\
			(target)->DelivType=(source)->DelivType;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef Copydeliv_clientEntity
#define Copydeliv_clientEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->OpSettlementID=(source)->OpSettlementID;	\
			(target)->cleardate=(source)->cleardate;	\
			(target)->delivdate=(source)->delivdate;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->AccountID=(source)->AccountID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->CommodityID=(source)->CommodityID;	\
			(target)->tdprice=(source)->tdprice;	\
			(target)->tdbtotamt=(source)->tdbtotamt;	\
			(target)->tdstotamt=(source)->tdstotamt;	\
			(target)->tdmargin=(source)->tdmargin;	\
			(target)->tdbrmamt=(source)->tdbrmamt;	\
			(target)->tdsrmamt=(source)->tdsrmamt;	\
			(target)->tdrmmargin=(source)->tdrmmargin;	\
			(target)->bzjtot=(source)->bzjtot;	\
			(target)->buytot=(source)->buytot;	\
			(target)->unjgbuy=(source)->unjgbuy;	\
			(target)->soldtot=(source)->soldtot;	\
			(target)->unjgsold=(source)->unjgsold;	\
			(target)->bzjret=(source)->bzjret;	\
			(target)->bzjuret=(source)->bzjuret;	\
			(target)->bdelivamt=(source)->bdelivamt;	\
			(target)->sdelivamt=(source)->sdelivamt;	\
			(target)->bactamt=(source)->bactamt;	\
			(target)->sactamt=(source)->sactamt;	\
			(target)->bjgje=(source)->bjgje;	\
			(target)->sjgje=(source)->sjgje;	\
			(target)->bupamt=(source)->bupamt;	\
			(target)->supamt=(source)->supamt;	\
			(target)->bdnamt=(source)->bdnamt;	\
			(target)->sdnamt=(source)->sdnamt;	\
			(target)->DelivBusiType=(source)->DelivBusiType;	\
			(target)->bank_id=(source)->bank_id;	\
			(target)->brandcode=(source)->brandcode;	\
			(target)->city=(source)->city;	\
			(target)->bzjretamt=(source)->bzjretamt;	\
			(target)->bzjuretamt=(source)->bzjuretamt;	\
			(target)->sbzjretamt=(source)->sbzjretamt;	\
			(target)->sbzjuretamt=(source)->sbzjuretamt;	\
			(target)->w_bupamt=(source)->w_bupamt;	\
			(target)->w_supamt=(source)->w_supamt;	\
			(target)->w_bdnamt=(source)->w_bdnamt;	\
			(target)->w_sdnamt=(source)->w_sdnamt;	\
			(target)->c_bupamt=(source)->c_bupamt;	\
			(target)->c_supamt=(source)->c_supamt;	\
			(target)->c_bdnamt=(source)->c_bdnamt;	\
			(target)->c_sdnamt=(source)->c_sdnamt;	\
			(target)->o_bupamt=(source)->o_bupamt;	\
			(target)->o_supamt=(source)->o_supamt;	\
			(target)->o_bdnamt=(source)->o_bdnamt;	\
			(target)->o_sdnamt=(source)->o_sdnamt;	\

#endif
#ifndef CopyClientDelivDetailEntity
#define CopyClientDelivDetailEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->SettlementID=(source)->SettlementID;	\
			(target)->DelivDate=(source)->DelivDate;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->DelivVolume=(source)->DelivVolume;	\
			(target)->DelivPrice=(source)->DelivPrice;	\
			(target)->DelivMoney=(source)->DelivMoney;	\
			(target)->DelivType=(source)->DelivType;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->OpDate=(source)->OpDate;	\
			(target)->OpTime=(source)->OpTime;	\

#endif
#ifndef CopyOptionPrickTickConditionEntity
#define CopyOptionPrickTickConditionEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->StartPrice=(source)->StartPrice;	\
			(target)->PriceTick=(source)->PriceTick;	\

#endif
#ifndef CopyInstrumentOptionTplEntity
#define CopyInstrumentOptionTplEntity(target,source)	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->OptPostLimitRatio=(source)->OptPostLimitRatio;	\
			(target)->UniPostLimitRatio=(source)->UniPostLimitRatio;	\
			(target)->MiniMargin=(source)->MiniMargin;	\
			(target)->PeriodId=(source)->PeriodId;	\
			(target)->PeriodName=(source)->PeriodName;	\
			(target)->StartDateExpr=(source)->StartDateExpr;	\

#endif
#ifndef CopyInstrumentOptionAttrEntity
#define CopyInstrumentOptionAttrEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->OptPostLimitRatio=(source)->OptPostLimitRatio;	\
			(target)->UniPostLimitRatio=(source)->UniPostLimitRatio;	\
			(target)->MiniMargin=(source)->MiniMargin;	\
			(target)->PeriodId=(source)->PeriodId;	\
			(target)->PeriodName=(source)->PeriodName;	\
			(target)->StartDateExpr=(source)->StartDateExpr;	\

#endif
#ifndef CopyCurrInstrumentOptionEntity
#define CopyCurrInstrumentOptionEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->OptPostLimitRatio=(source)->OptPostLimitRatio;	\
			(target)->UniPostLimitRatio=(source)->UniPostLimitRatio;	\
			(target)->MiniMargin=(source)->MiniMargin;	\
			(target)->OptHedgeLimitRatio=(source)->OptHedgeLimitRatio;	\
			(target)->UniHedgeLimitRatio=(source)->UniHedgeLimitRatio;	\
			(target)->OptOpenPostLimitRatio=(source)->OptOpenPostLimitRatio;	\
			(target)->UniOpenPostLimitRatio=(source)->UniOpenPostLimitRatio;	\
			(target)->OptOpenHedgeLimitRatio=(source)->OptOpenHedgeLimitRatio;	\
			(target)->UniOpenHedgeLimitRatio=(source)->UniOpenHedgeLimitRatio;	\

#endif
#ifndef CopyCurrInstrumentOptionExEntity
#define CopyCurrInstrumentOptionExEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->OptPostLimitRatio=(source)->OptPostLimitRatio;	\
			(target)->UniPostLimitRatio=(source)->UniPostLimitRatio;	\
			(target)->MiniMargin=(source)->MiniMargin;	\
			(target)->OptHedgeLimitRatio=(source)->OptHedgeLimitRatio;	\
			(target)->UniHedgeLimitRatio=(source)->UniHedgeLimitRatio;	\
			(target)->OptOpenPostLimitRatio=(source)->OptOpenPostLimitRatio;	\
			(target)->UniOpenPostLimitRatio=(source)->UniOpenPostLimitRatio;	\
			(target)->OptOpenHedgeLimitRatio=(source)->OptOpenHedgeLimitRatio;	\
			(target)->UniOpenHedgeLimitRatio=(source)->UniOpenHedgeLimitRatio;	\

#endif
#ifndef CopyClockDeltaEntity
#define CopyClockDeltaEntity(target,source)	\
			(target)->SecondDelta=(source)->SecondDelta;	\
			(target)->MilliSecondDelta=(source)->MilliSecondDelta;	\

#endif
#ifndef CopyIcmiMarketDataEntity
#define CopyIcmiMarketDataEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->SettlementPrice=(source)->SettlementPrice;	\
			(target)->Volume=(source)->Volume;	\
			(target)->Turnover=(source)->Turnover;	\
			(target)->OpenInterest=(source)->OpenInterest;	\

#endif
#ifndef CopyIcmiPositionMoneyMonthlyEntity
#define CopyIcmiPositionMoneyMonthlyEntity(target,source)	\
			(target)->TradingYearMonth=(source)->TradingYearMonth;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->PositionMoney=(source)->PositionMoney;	\

#endif
#ifndef CopyIcmiDefineEntity
#define CopyIcmiDefineEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->IndexName=(source)->IndexName;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->IndexBaseLine=(source)->IndexBaseLine;	\
			(target)->IndexBaseValue=(source)->IndexBaseValue;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ProductGroupID=(source)->ProductGroupID;	\
			(target)->IndexProductIDs=(source)->IndexProductIDs;	\

#endif
#ifndef CopyIcmiCompositionEntity
#define CopyIcmiCompositionEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->CompositionInstrument=(source)->CompositionInstrument;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->RollingType=(source)->RollingType;	\
			(target)->RollingWeight=(source)->RollingWeight;	\

#endif
#ifndef CopyIcmiWeightEntity
#define CopyIcmiWeightEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ProductWeight=(source)->ProductWeight;	\

#endif
#ifndef CopyIcmiStandardConstEntity
#define CopyIcmiStandardConstEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->StandardConst=(source)->StandardConst;	\

#endif
#ifndef CopyBizParameterEntity
#define CopyBizParameterEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			(target)->ParamName=(source)->ParamName;	\
			(target)->ParamValue=(source)->ParamValue;	\

#endif
#ifndef CopyExchangeRateEntity
#define CopyExchangeRateEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->CurrencyID=(source)->CurrencyID;	\
			(target)->RateUnit=(source)->RateUnit;	\
			(target)->RatePrice=(source)->RatePrice;	\

#endif
#ifndef CopyOrderSessionEntity
#define CopyOrderSessionEntity(target,source)	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->SessionID=(source)->SessionID;	\
			(target)->RequestID=(source)->RequestID;	\

#endif
#ifndef CopyUserMeasureEntity
#define CopyUserMeasureEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->SessionType=(source)->SessionType;	\
			(target)->Msec=(source)->Msec;	\

#endif
#ifndef CopyLoopMeasureEntity
#define CopyLoopMeasureEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->SessionType=(source)->SessionType;	\
			(target)->MeasureSeq=(source)->MeasureSeq;	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->SessionID=(source)->SessionID;	\

#endif
#ifndef CopyNodeMeasureEntity
#define CopyNodeMeasureEntity(target,source)	\
			(target)->NodeID=(source)->NodeID;	\
			(target)->PeriodID=(source)->PeriodID;	\
			(target)->Sec=(source)->Sec;	\
			(target)->Usec=(source)->Usec;	\

#endif
#ifndef CopyLoopMeasureRecordEntity
#define CopyLoopMeasureRecordEntity(target,source)	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			CopyLoopMeasureEntity(target,source);	\
			CopyNodeMeasureEntity(target,source);	\

#endif
#ifndef CopyCurrReferenceInstrumentEntity
#define CopyCurrReferenceInstrumentEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->TopicID=(source)->TopicID;	\
			(target)->UnderlyingInstrID=(source)->UnderlyingInstrID;	\
			(target)->MdAlgorithm=(source)->MdAlgorithm;	\
			(target)->RoundingMode=(source)->RoundingMode;	\
			(target)->MarketDataTick=(source)->MarketDataTick;	\

#endif
#ifndef CopyPartClientProductGrpMarginEntity
#define CopyPartClientProductGrpMarginEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->GroupName=(source)->GroupName;	\
			(target)->CurrLongTradeMargin=(source)->CurrLongTradeMargin;	\
			(target)->CurrLongFrozenMargin=(source)->CurrLongFrozenMargin;	\
			(target)->CurrShortTradeMargin=(source)->CurrShortTradeMargin;	\
			(target)->CurrShortFrozenMargin=(source)->CurrShortFrozenMargin;	\
			(target)->CurrTradeMargin=(source)->CurrTradeMargin;	\
			(target)->CurrFrozenMargin=(source)->CurrFrozenMargin;	\

#endif
#ifndef CopyProductMarginDeductRateEntity
#define CopyProductMarginDeductRateEntity(target,source)	\
			CopySettlementRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->DeductibleRatio=(source)->DeductibleRatio;	\
			(target)->GroupName=(source)->GroupName;	\

#endif
#ifndef CopyMDProxyEntity
#define CopyMDProxyEntity(target,source)	\
			(target)->ProxyID=(source)->ProxyID;	\
			(target)->UpperProxySessionID=(source)->UpperProxySessionID;	\
			(target)->CurrProxySessionID=(source)->CurrProxySessionID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->RequestID=(source)->RequestID;	\
			(target)->Depth=(source)->Depth;	\
			(target)->SessionStatus=(source)->SessionStatus;	\
			(target)->DeletedSessionID=(source)->DeletedSessionID;	\
			(target)->MaxCommFlux=(source)->MaxCommFlux;	\

#endif
#ifndef CopyMDProxySessionEntity
#define CopyMDProxySessionEntity(target,source)	\
			(target)->ProxyID=(source)->ProxyID;	\
			(target)->SessionID=(source)->SessionID;	\
			(target)->ProxySessionID=(source)->ProxySessionID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->IsLogin=(source)->IsLogin;	\

#endif
#ifndef CopyPartClientProductMarketMakerEntity
#define CopyPartClientProductMarketMakerEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ProductID=(source)->ProductID;	\

#endif
#ifndef CopyUserPartProductMarketMakerEntity
#define CopyUserPartProductMarketMakerEntity(target,source)	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->SessionID=(source)->SessionID;	\
			(target)->IsLogin=(source)->IsLogin;	\

#endif
#ifndef CopyInputQuoteDemandEntity
#define CopyInputQuoteDemandEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->QuoteDemandLocalID=(source)->QuoteDemandLocalID;	\

#endif
#ifndef CopyQuoteDemandInfoEntity
#define CopyQuoteDemandInfoEntity(target,source)	\
			CopyTradingDayRefEntity(target,source);	\
			CopyInputQuoteDemandEntity(target,source);	\
			(target)->DemandTime=(source)->DemandTime;	\
			(target)->ActionDay=(source)->ActionDay;	\

#endif
#ifndef CopyQuoteDemandInfoDetailEntity
#define CopyQuoteDemandInfoDetailEntity(target,source)	\
			CopyQuoteDemandInfoEntity(target,source);	\
			(target)->QuoteDemandID=(source)->QuoteDemandID;	\

#endif
#ifndef CopyQuoteDemandNotifyEntity
#define CopyQuoteDemandNotifyEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->DemandDay=(source)->DemandDay;	\
			(target)->DemandTime=(source)->DemandTime;	\

#endif
#ifndef CopyOptionHedgeVolumeEntity
#define CopyOptionHedgeVolumeEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->UnderlyingInstrID=(source)->UnderlyingInstrID;	\
			(target)->OptLongLimit=(source)->OptLongLimit;	\
			(target)->OptShortLimit=(source)->OptShortLimit;	\
			(target)->OptLongVolume=(source)->OptLongVolume;	\
			(target)->OptShortVolume=(source)->OptShortVolume;	\
			(target)->UniLongLimit=(source)->UniLongLimit;	\
			(target)->UniShortLimit=(source)->UniShortLimit;	\
			(target)->UniLongVolume=(source)->UniLongVolume;	\
			(target)->UniShortVolume=(source)->UniShortVolume;	\

#endif
#ifndef CopyInstrumentMdStatusEntity
#define CopyInstrumentMdStatusEntity(target,source)	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->SnapShotFreq=(source)->SnapShotFreq;	\
			(target)->LastModifyNo=(source)->LastModifyNo;	\

#endif
#ifndef CopyCurrClientOpenPosiLimitEntity
#define CopyCurrClientOpenPosiLimitEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->OpenPosLimit=(source)->OpenPosLimit;	\

#endif
#ifndef CopyClientOpenPositionEntity
#define CopyClientOpenPositionEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->PosiOpenTodayFrozen=(source)->PosiOpenTodayFrozen;	\
			(target)->PosiOpenToday=(source)->PosiOpenToday;	\

#endif
#ifndef CopyCurrClientOpenPosiLimitDetailEntity
#define CopyCurrClientOpenPosiLimitDetailEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->OpenPosLimit=(source)->OpenPosLimit;	\

#endif
#ifndef CopyClientProductOrderFluxEntity
#define CopyClientProductOrderFluxEntity(target,source)	\
			CopySettlementGroupRefEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->OrderLimit=(source)->OrderLimit;	\
			(target)->CancelLimit=(source)->CancelLimit;	\

#endif
#ifndef CopyClientProductOrderFluxDetailEntity
#define CopyClientProductOrderFluxDetailEntity(target,source)	\
			(target)->ProductID=(source)->ProductID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->OrderLimit=(source)->OrderLimit;	\
			(target)->CancelLimit=(source)->CancelLimit;	\
			(target)->CurrOrderCount=(source)->CurrOrderCount;	\
			(target)->CurrCancelCount=(source)->CurrCancelCount;	\
			(target)->TimeSec=(source)->TimeSec;	\

#endif
#ifndef CopyUserapiAuthenticInfoEntity
#define CopyUserapiAuthenticInfoEntity(target,source)	\
			(target)->EncryptUserApiInfo=(source)->EncryptUserApiInfo;	\

#endif
#ifndef CopyUserProductAuthenticInfoEntity
#define CopyUserProductAuthenticInfoEntity(target,source)	\
			(target)->EncryptProductInfo=(source)->EncryptProductInfo;	\

#endif
#ifndef CopyUserapiInitAuthInfoEntity
#define CopyUserapiInitAuthInfoEntity(target,source)	\
			(target)->InitEncryptInfo=(source)->InitEncryptInfo;	\

#endif
#ifndef CopyUserConnectFrontTypeEntity
#define CopyUserConnectFrontTypeEntity(target,source)	\
			(target)->UserConnectFrontType=(source)->UserConnectFrontType;	\

#endif
#ifndef CopyUserProductKeyEntity
#define CopyUserProductKeyEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserProductInfo=(source)->UserProductInfo;	\
			(target)->EncryptType=(source)->EncryptType;	\
			(target)->EncryptKey=(source)->EncryptKey;	\

#endif
#ifndef CopyMortgageDepositEntity
#define CopyMortgageDepositEntity(target,source)	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->BizID=(source)->BizID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->Account=(source)->Account;	\
			(target)->Deposit=(source)->Deposit;	\
			(target)->Reserve=(source)->Reserve;	\

#endif
#ifndef CopyDbmtMortgageDepositEntity
#define CopyDbmtMortgageDepositEntity(target,source)	\
			CopyMortgageDepositEntity(target,source);	\
			CopyDbmtRefEntity(target,source);	\

#endif
#ifndef CopyMortgageDepositResultEntity
#define CopyMortgageDepositResultEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->BizID=(source)->BizID;	\
			(target)->SequenceNo=(source)->SequenceNo;	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ActionMillisec=(source)->ActionMillisec;	\
			(target)->Result=(source)->Result;	\
			(target)->Reason=(source)->Reason;	\

#endif
#ifndef CopyMDSnapShotEntity
#define CopyMDSnapShotEntity(target,source)	\
			CopyMarketDataEntity(target,source);	\
			(target)->ProductID=(source)->ProductID;	\

#endif
#ifndef CopyTopCpuInfoEntity
#define CopyTopCpuInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CPU=(source)->CPU;	\
			(target)->LOAD=(source)->LOAD;	\
			(target)->USER=(source)->USER;	\
			(target)->NICE=(source)->NICE;	\
			(target)->SYS=(source)->SYS;	\
			(target)->IDLE=(source)->IDLE;	\
			(target)->BLOCK=(source)->BLOCK;	\
			(target)->SWAIT=(source)->SWAIT;	\
			(target)->INTR=(source)->INTR;	\
			(target)->SSYS=(source)->SSYS;	\

#endif
#ifndef CopyReqQryTopCpuInfoEntity
#define CopyReqQryTopCpuInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->CPU=(source)->CPU;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryTopCpuInfoEntity
#define CopyRspQryTopCpuInfoEntity(target,source)	\
			CopyTopCpuInfoEntity(target,source);	\

#endif
#ifndef CopyRtnTopCpuInfoEntity
#define CopyRtnTopCpuInfoEntity(target,source)	\
			CopyTopCpuInfoEntity(target,source);	\

#endif
#ifndef CopyTopMemInfoEntity
#define CopyTopMemInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->TOTALREAL=(source)->TOTALREAL;	\
			(target)->ACTIVEREAL=(source)->ACTIVEREAL;	\
			(target)->TOTALVIRTUAL=(source)->TOTALVIRTUAL;	\
			(target)->ACTIVEVIRTUAL=(source)->ACTIVEVIRTUAL;	\
			(target)->FREE=(source)->FREE;	\

#endif
#ifndef CopyReqQryTopMemInfoEntity
#define CopyReqQryTopMemInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryTopMemInfoEntity
#define CopyRspQryTopMemInfoEntity(target,source)	\
			CopyTopMemInfoEntity(target,source);	\

#endif
#ifndef CopyRtnTopMemInfoEntity
#define CopyRtnTopMemInfoEntity(target,source)	\
			CopyTopMemInfoEntity(target,source);	\

#endif
#ifndef CopyTopProcessInfoEntity
#define CopyTopProcessInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CPU=(source)->CPU;	\
			(target)->TTY=(source)->TTY;	\
			(target)->PID=(source)->PID;	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->PRI=(source)->PRI;	\
			(target)->NI=(source)->NI;	\
			(target)->SIZE=(source)->SIZE;	\
			(target)->RES=(source)->RES;	\
			(target)->STATE=(source)->STATE;	\
			(target)->TIME=(source)->TIME;	\
			(target)->pWCPU=(source)->pWCPU;	\
			(target)->pCPU=(source)->pCPU;	\
			(target)->COMMAND=(source)->COMMAND;	\

#endif
#ifndef CopyReqQryTopProcessInfoEntity
#define CopyReqQryTopProcessInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryTopProcessInfoEntity
#define CopyRspQryTopProcessInfoEntity(target,source)	\
			CopyTopProcessInfoEntity(target,source);	\

#endif
#ifndef CopyRtnTopProcessInfoEntity
#define CopyRtnTopProcessInfoEntity(target,source)	\
			CopyTopProcessInfoEntity(target,source);	\

#endif
#ifndef CopyMonitorTopProcessInfoEntity
#define CopyMonitorTopProcessInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CPU=(source)->CPU;	\
			(target)->TTY=(source)->TTY;	\
			(target)->PID=(source)->PID;	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->PRI=(source)->PRI;	\
			(target)->NI=(source)->NI;	\
			(target)->SSIZE=(source)->SSIZE;	\
			(target)->RES=(source)->RES;	\
			(target)->STATE=(source)->STATE;	\
			(target)->STIME=(source)->STIME;	\
			(target)->pWCPU=(source)->pWCPU;	\
			(target)->pCPU=(source)->pCPU;	\
			(target)->COMMAND=(source)->COMMAND;	\

#endif
#ifndef CopyFileSystemInfoEntity
#define CopyFileSystemInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->FILESYSTEM=(source)->FILESYSTEM;	\
			(target)->SIZE=(source)->SIZE;	\
			(target)->USED=(source)->USED;	\
			(target)->AVAIL=(source)->AVAIL;	\
			(target)->pUSERD=(source)->pUSERD;	\
			(target)->ISIZE=(source)->ISIZE;	\
			(target)->IUSED=(source)->IUSED;	\
			(target)->IFREE=(source)->IFREE;	\
			(target)->pIUSED=(source)->pIUSED;	\
			(target)->MountedOn=(source)->MountedOn;	\

#endif
#ifndef CopyReqQryFileSystemInfoEntity
#define CopyReqQryFileSystemInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryFileSystemInfoEntity
#define CopyRspQryFileSystemInfoEntity(target,source)	\
			CopyFileSystemInfoEntity(target,source);	\

#endif
#ifndef CopyRtnFileSystemInfoEntity
#define CopyRtnFileSystemInfoEntity(target,source)	\
			CopyFileSystemInfoEntity(target,source);	\

#endif
#ifndef CopyNetworkInfoEntity
#define CopyNetworkInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->LANNAME=(source)->LANNAME;	\
			(target)->LANSTATUS=(source)->LANSTATUS;	\
			(target)->IPADDRESS=(source)->IPADDRESS;	\
			(target)->RECVBYTES=(source)->RECVBYTES;	\
			(target)->RECVPACKETS=(source)->RECVPACKETS;	\
			(target)->RECVERRORPACKETS=(source)->RECVERRORPACKETS;	\
			(target)->RECVDROPPACKETS=(source)->RECVDROPPACKETS;	\
			(target)->SENDBYTES=(source)->SENDBYTES;	\
			(target)->SENDPACKETS=(source)->SENDPACKETS;	\
			(target)->SENDERRORPACKETS=(source)->SENDERRORPACKETS;	\
			(target)->SENDDROPPACKETS=(source)->SENDDROPPACKETS;	\

#endif
#ifndef CopyReqQryNetworkInfoEntity
#define CopyReqQryNetworkInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->LANNAME=(source)->LANNAME;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryNetworkInfoEntity
#define CopyRspQryNetworkInfoEntity(target,source)	\
			CopyNetworkInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetworkInfoEntity
#define CopyRtnNetworkInfoEntity(target,source)	\
			CopyNetworkInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryHostEnvEntity
#define CopyReqQryHostEnvEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryHostEnvCommonEntity
#define CopyRspQryHostEnvCommonEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->HostModel=(source)->HostModel;	\
			(target)->MainMemory=(source)->MainMemory;	\
			(target)->CPUVendor=(source)->CPUVendor;	\
			(target)->CPUModel=(source)->CPUModel;	\
			(target)->CPUMHz=(source)->CPUMHz;	\
			(target)->CPUCache=(source)->CPUCache;	\
			(target)->CPUCores=(source)->CPUCores;	\
			(target)->Processors=(source)->Processors;	\
			(target)->OsMode=(source)->OsMode;	\

#endif
#ifndef CopyRspQryHostEnvLanEntity
#define CopyRspQryHostEnvLanEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->LanHardwareID=(source)->LanHardwareID;	\
			(target)->LanHardwareValue=(source)->LanHardwareValue;	\

#endif
#ifndef CopyRspQryHostEnvStorageEntity
#define CopyRspQryHostEnvStorageEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->StorageDev=(source)->StorageDev;	\
			(target)->HWPath=(source)->HWPath;	\
			(target)->Interface=(source)->Interface;	\

#endif
#ifndef CopyRspQryHostEnvIOEntity
#define CopyRspQryHostEnvIOEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->IoClass=(source)->IoClass;	\
			(target)->H_WPath=(source)->H_WPath;	\
			(target)->IoDriver=(source)->IoDriver;	\
			(target)->IoDescription=(source)->IoDescription;	\

#endif
#ifndef CopyRspQryHostEnvFSEntity
#define CopyRspQryHostEnvFSEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->LVMDeviceFile=(source)->LVMDeviceFile;	\
			(target)->MountPoint=(source)->MountPoint;	\
			(target)->FSsize=(source)->FSsize;	\
			(target)->FSType=(source)->FSType;	\

#endif
#ifndef CopyRspQryHostEnvSwapEntity
#define CopyRspQryHostEnvSwapEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->type=(source)->type;	\
			(target)->size=(source)->size;	\
			(target)->priority=(source)->priority;	\
			(target)->location=(source)->location;	\

#endif
#ifndef CopyRspQryHostEnvLanCfgEntity
#define CopyRspQryHostEnvLanCfgEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->LanName=(source)->LanName;	\
			(target)->IpAddress=(source)->IpAddress;	\
			(target)->IpMask=(source)->IpMask;	\

#endif
#ifndef CopyReqQryClientLoginEntity
#define CopyReqQryClientLoginEntity(target,source)	\
			(target)->UserName=(source)->UserName;	\
			(target)->PassWord=(source)->PassWord;	\

#endif
#ifndef CopyRspQryClientLoginEntity
#define CopyRspQryClientLoginEntity(target,source)	\
			(target)->UserName=(source)->UserName;	\
			(target)->Privalage=(source)->Privalage;	\

#endif
#ifndef CopyReqQryMonitorObjectEntity
#define CopyReqQryMonitorObjectEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryMonitorObjectEntity
#define CopyRspQryMonitorObjectEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->ObjectName=(source)->ObjectName;	\
			(target)->WarningActive=(source)->WarningActive;	\

#endif
#ifndef CopyRtnMonitorObjectEntity
#define CopyRtnMonitorObjectEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->ObjectName=(source)->ObjectName;	\
			(target)->WarningActive=(source)->WarningActive;	\

#endif
#ifndef CopyReqQryObjectRationalEntity
#define CopyReqQryObjectRationalEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryObjectRationalEntity
#define CopyRspQryObjectRationalEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->HostObjectID=(source)->HostObjectID;	\

#endif
#ifndef CopyRtnObjectRationalEntity
#define CopyRtnObjectRationalEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->HostObjectID=(source)->HostObjectID;	\

#endif
#ifndef CopyReqQrySyslogInfoEntity
#define CopyReqQrySyslogInfoEntity(target,source)	\
			(target)->FileName=(source)->FileName;	\
			(target)->subFileName=(source)->subFileName;	\

#endif
#ifndef CopySysSyslogInfoEntity
#define CopySysSyslogInfoEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->ContLen=(source)->ContLen;	\
			(target)->FileContent=(source)->FileContent;	\

#endif
#ifndef CopyRspQrySyslogInfoEntity
#define CopyRspQrySyslogInfoEntity(target,source)	\
			CopySysSyslogInfoEntity(target,source);	\

#endif
#ifndef CopyRtnSyslogInfoEntity
#define CopyRtnSyslogInfoEntity(target,source)	\
			CopySysSyslogInfoEntity(target,source);	\

#endif
#ifndef CopyReqQrySubscriberEntity
#define CopyReqQrySubscriberEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->ObjectNum=(source)->ObjectNum;	\
			(target)->KeepAlive=(source)->KeepAlive;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\

#endif
#ifndef CopyRspQrySubscriberEntity
#define CopyRspQrySubscriberEntity(target,source)	\
			CopyErrorTypeEntity(target,source);	\
			(target)->ObjectID=(source)->ObjectID;	\

#endif
#ifndef CopyRtnSubscriberEntity
#define CopyRtnSubscriberEntity(target,source)	\
			CopyErrorTypeEntity(target,source);	\
			(target)->ObjectID=(source)->ObjectID;	\

#endif
#ifndef CopyReqQryOidRelationEntity
#define CopyReqQryOidRelationEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\

#endif
#ifndef CopySysOidRelationEntity
#define CopySysOidRelationEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->HoldObjectID=(source)->HoldObjectID;	\

#endif
#ifndef CopyRspQryOidRelationEntity
#define CopyRspQryOidRelationEntity(target,source)	\
			CopySysOidRelationEntity(target,source);	\

#endif
#ifndef CopyRtnOidRelationEntity
#define CopyRtnOidRelationEntity(target,source)	\
			CopySysOidRelationEntity(target,source);	\

#endif
#ifndef CopyReqQryUserInfoEntity
#define CopyReqQryUserInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysUserInfoEntity
#define CopySysUserInfoEntity(target,source)	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->USERID=(source)->USERID;	\
			(target)->GROUPNAME=(source)->GROUPNAME;	\
			(target)->GROUPID=(source)->GROUPID;	\
			(target)->HOMEPATH=(source)->HOMEPATH;	\
			(target)->SHELL=(source)->SHELL;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->MonDate=(source)->MonDate;	\

#endif
#ifndef CopyRspQryUserInfoEntity
#define CopyRspQryUserInfoEntity(target,source)	\
			CopySysUserInfoEntity(target,source);	\

#endif
#ifndef CopyRtnUserInfoEntity
#define CopyRtnUserInfoEntity(target,source)	\
			CopySysUserInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryOnlineUserInfoEntity
#define CopyReqQryOnlineUserInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysOnlineUserInfoEntity
#define CopySysOnlineUserInfoEntity(target,source)	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->TIME=(source)->TIME;	\
			(target)->TTY=(source)->TTY;	\
			(target)->IP=(source)->IP;	\
			(target)->CONNECTIME=(source)->CONNECTIME;	\
			(target)->PID=(source)->PID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->MonDate=(source)->MonDate;	\

#endif
#ifndef CopyRspQryOnlineUserInfoEntity
#define CopyRspQryOnlineUserInfoEntity(target,source)	\
			CopySysOnlineUserInfoEntity(target,source);	\

#endif
#ifndef CopyRtnOnlineUserInfoEntity
#define CopyRtnOnlineUserInfoEntity(target,source)	\
			CopySysOnlineUserInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryWarningEventEntity
#define CopyReqQryWarningEventEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->WarningLevel=(source)->WarningLevel;	\
			(target)->EventType=(source)->EventType;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->EventName=(source)->EventName;	\

#endif
#ifndef CopyReqQrySyslogEventEntity
#define CopyReqQrySyslogEventEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->EventType=(source)->EventType;	\
			(target)->WarningLevel=(source)->WarningLevel;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->EventName=(source)->EventName;	\
			(target)->IPAddress=(source)->IPAddress;	\

#endif
#ifndef CopySysWarningEventEntity
#define CopySysWarningEventEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->OccurDate=(source)->OccurDate;	\
			(target)->OccurTime=(source)->OccurTime;	\
			(target)->EvendID=(source)->EvendID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->EventName=(source)->EventName;	\
			(target)->EventNum=(source)->EventNum;	\
			(target)->EventType=(source)->EventType;	\
			(target)->EventDes=(source)->EventDes;	\
			(target)->ProcessFlag=(source)->ProcessFlag;	\
			(target)->WarningLevel=(source)->WarningLevel;	\
			(target)->EventDealDes=(source)->EventDealDes;	\
			(target)->FullEventName=(source)->FullEventName;	\

#endif
#ifndef CopyRspQryWarningEventEntity
#define CopyRspQryWarningEventEntity(target,source)	\
			CopySysWarningEventEntity(target,source);	\

#endif
#ifndef CopyRtnWarningEventEntity
#define CopyRtnWarningEventEntity(target,source)	\
			CopySysWarningEventEntity(target,source);	\
			(target)->EventCount=(source)->EventCount;	\

#endif
#ifndef CopyRspQrySyslogEventEntity
#define CopyRspQrySyslogEventEntity(target,source)	\
			CopySysWarningEventEntity(target,source);	\
			(target)->EventCount=(source)->EventCount;	\

#endif
#ifndef CopyRtnSyslogEventEntity
#define CopyRtnSyslogEventEntity(target,source)	\
			CopySysWarningEventEntity(target,source);	\

#endif
#ifndef CopyReqQrySyslogEventUpdateEntity
#define CopyReqQrySyslogEventUpdateEntity(target,source)	\
			CopySysWarningEventEntity(target,source);	\

#endif
#ifndef CopyReqQrySyslogEventSubcriberEntity
#define CopyReqQrySyslogEventSubcriberEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->EventName=(source)->EventName;	\
			(target)->WarningLevel=(source)->WarningLevel;	\
			(target)->filter=(source)->filter;	\
			(target)->antifilter=(source)->antifilter;	\
			(target)->ObjectNum=(source)->ObjectNum;	\
			(target)->KeepAlive=(source)->KeepAlive;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ProcessFlag=(source)->ProcessFlag;	\

#endif
#ifndef CopyReqQryWarningEventUpdateEntity
#define CopyReqQryWarningEventUpdateEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->OccurDate=(source)->OccurDate;	\
			(target)->OccurTime=(source)->OccurTime;	\
			(target)->EvendID=(source)->EvendID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->EventName=(source)->EventName;	\
			(target)->EventNum=(source)->EventNum;	\
			(target)->EventType=(source)->EventType;	\
			(target)->EventDes=(source)->EventDes;	\
			(target)->ProcessFlag=(source)->ProcessFlag;	\
			(target)->WarningLevel=(source)->WarningLevel;	\
			(target)->ActiveDate=(source)->ActiveDate;	\
			(target)->ActiveTime=(source)->ActiveTime;	\
			(target)->EventDealDes=(source)->EventDealDes;	\
			(target)->FullEventName=(source)->FullEventName;	\

#endif
#ifndef CopyReqQryCPUUsageEntity
#define CopyReqQryCPUUsageEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysCPUUsageEntity
#define CopySysCPUUsageEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CPUUsage=(source)->CPUUsage;	\

#endif
#ifndef CopyRspQryCPUUsageEntity
#define CopyRspQryCPUUsageEntity(target,source)	\
			CopySysCPUUsageEntity(target,source);	\

#endif
#ifndef CopyRtnCPUUsageEntity
#define CopyRtnCPUUsageEntity(target,source)	\
			CopySysCPUUsageEntity(target,source);	\

#endif
#ifndef CopyReqQryMemoryUsageEntity
#define CopyReqQryMemoryUsageEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysMemoryUsageEntity
#define CopySysMemoryUsageEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->MemoryUsage=(source)->MemoryUsage;	\

#endif
#ifndef CopyRspQryMemoryUsageEntity
#define CopyRspQryMemoryUsageEntity(target,source)	\
			CopySysMemoryUsageEntity(target,source);	\

#endif
#ifndef CopyRtnMemoryUsageEntity
#define CopyRtnMemoryUsageEntity(target,source)	\
			CopySysMemoryUsageEntity(target,source);	\

#endif
#ifndef CopyReqQryDiskUsageEntity
#define CopyReqQryDiskUsageEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysDiskUsageEntity
#define CopySysDiskUsageEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->DiskUsage=(source)->DiskUsage;	\

#endif
#ifndef CopyRspQryDiskUsageEntity
#define CopyRspQryDiskUsageEntity(target,source)	\
			CopySysDiskUsageEntity(target,source);	\

#endif
#ifndef CopyRtnDiskUsageEntity
#define CopyRtnDiskUsageEntity(target,source)	\
			CopySysDiskUsageEntity(target,source);	\

#endif
#ifndef CopyReqQryKeyFileInfoEntity
#define CopyReqQryKeyFileInfoEntity(target,source)	\
			(target)->FileName=(source)->FileName;	\
			(target)->PathName=(source)->PathName;	\

#endif
#ifndef CopyReqQryHostMonitorCfgEntity
#define CopyReqQryHostMonitorCfgEntity(target,source)	\
			(target)->MonitorType=(source)->MonitorType;	\
			(target)->PathName=(source)->PathName;	\
			(target)->Interval=(source)->Interval;	\

#endif
#ifndef CopyReqQryAppMonitorCfgEntity
#define CopyReqQryAppMonitorCfgEntity(target,source)	\
			(target)->MonitorType=(source)->MonitorType;	\
			(target)->FSPosition=(source)->FSPosition;	\

#endif
#ifndef CopyReqQryDBQueryEntity
#define CopyReqQryDBQueryEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysDBQueryEntity
#define CopySysDBQueryEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->DBQueryResult=(source)->DBQueryResult;	\

#endif
#ifndef CopySysMdbDBQueryEntity
#define CopySysMdbDBQueryEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->DBQueryResult=(source)->DBQueryResult;	\

#endif
#ifndef CopyRspQryDBQueryEntity
#define CopyRspQryDBQueryEntity(target,source)	\
			CopySysDBQueryEntity(target,source);	\

#endif
#ifndef CopyRtnDBQueryEntity
#define CopyRtnDBQueryEntity(target,source)	\
			CopySysDBQueryEntity(target,source);	\

#endif
#ifndef CopyReqQryHostConfigEntity
#define CopyReqQryHostConfigEntity(target,source)	\
			(target)->CfgType=(source)->CfgType;	\
			(target)->CfgDataCenter=(source)->CfgDataCenter;	\
			(target)->CfgName=(source)->CfgName;	\
			(target)->CfgLocation=(source)->CfgLocation;	\
			(target)->CfgHostName=(source)->CfgHostName;	\
			(target)->CfgAttend=(source)->CfgAttend;	\

#endif
#ifndef CopyRspQryHostConfigEntity
#define CopyRspQryHostConfigEntity(target,source)	\
			CopyReqQryHostConfigEntity(target,source);	\

#endif
#ifndef CopyRtnHostConfigEntity
#define CopyRtnHostConfigEntity(target,source)	\
			CopyReqQryHostConfigEntity(target,source);	\

#endif
#ifndef CopySysMdbSyslogInfoEntity
#define CopySysMdbSyslogInfoEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->ContLen=(source)->ContLen;	\
			(target)->FileContent=(source)->FileContent;	\

#endif
#ifndef CopySysMdbTopCpuInfoEntity
#define CopySysMdbTopCpuInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CPU=(source)->CPU;	\
			(target)->LOAD=(source)->LOAD;	\
			(target)->USER=(source)->USER;	\
			(target)->NICE=(source)->NICE;	\
			(target)->SYS=(source)->SYS;	\
			(target)->IDLE=(source)->IDLE;	\
			(target)->BLOCK=(source)->BLOCK;	\
			(target)->SWAIT=(source)->SWAIT;	\
			(target)->INTR=(source)->INTR;	\
			(target)->SSYS=(source)->SSYS;	\

#endif
#ifndef CopySysMdbTopMemInfoEntity
#define CopySysMdbTopMemInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->TOTALREAL=(source)->TOTALREAL;	\
			(target)->ACTIVEREAL=(source)->ACTIVEREAL;	\
			(target)->TOTALVIRTUAL=(source)->TOTALVIRTUAL;	\
			(target)->ACTIVEVIRTUAL=(source)->ACTIVEVIRTUAL;	\
			(target)->FREE=(source)->FREE;	\

#endif
#ifndef CopySysMdbTopProcessInfoEntity
#define CopySysMdbTopProcessInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CPU=(source)->CPU;	\
			(target)->TTY=(source)->TTY;	\
			(target)->PID=(source)->PID;	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->PRI=(source)->PRI;	\
			(target)->NI=(source)->NI;	\
			(target)->SIZE=(source)->SIZE;	\
			(target)->RES=(source)->RES;	\
			(target)->STATE=(source)->STATE;	\
			(target)->TIME=(source)->TIME;	\
			(target)->pWCPU=(source)->pWCPU;	\
			(target)->pCPU=(source)->pCPU;	\
			(target)->COMMAND=(source)->COMMAND;	\

#endif
#ifndef CopySysMdbFileSystemInfoEntity
#define CopySysMdbFileSystemInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->FILESYSTEM=(source)->FILESYSTEM;	\
			(target)->SIZE=(source)->SIZE;	\
			(target)->USED=(source)->USED;	\
			(target)->AVAIL=(source)->AVAIL;	\
			(target)->pUSERD=(source)->pUSERD;	\
			(target)->ISIZE=(source)->ISIZE;	\
			(target)->IUSED=(source)->IUSED;	\
			(target)->IFREE=(source)->IFREE;	\
			(target)->pIUSED=(source)->pIUSED;	\
			(target)->MountedOn=(source)->MountedOn;	\

#endif
#ifndef CopySysMdbNetworkInfoEntity
#define CopySysMdbNetworkInfoEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->LANNAME=(source)->LANNAME;	\
			(target)->LANSTATUS=(source)->LANSTATUS;	\
			(target)->IPADDRESS=(source)->IPADDRESS;	\
			(target)->RECVBYTES=(source)->RECVBYTES;	\
			(target)->RECVPACKETS=(source)->RECVPACKETS;	\
			(target)->RECVERRORPACKETS=(source)->RECVERRORPACKETS;	\
			(target)->RECVDROPPACKETS=(source)->RECVDROPPACKETS;	\
			(target)->SENDBYTES=(source)->SENDBYTES;	\
			(target)->SENDPACKETS=(source)->SENDPACKETS;	\
			(target)->SENDERRORPACKETS=(source)->SENDERRORPACKETS;	\
			(target)->SENDDROPPACKETS=(source)->SENDDROPPACKETS;	\

#endif
#ifndef CopySysMdbUserInfoEntity
#define CopySysMdbUserInfoEntity(target,source)	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->USERID=(source)->USERID;	\
			(target)->GROUPNAME=(source)->GROUPNAME;	\
			(target)->GROUPID=(source)->GROUPID;	\
			(target)->HOMEPATH=(source)->HOMEPATH;	\
			(target)->SHELL=(source)->SHELL;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\

#endif
#ifndef CopySysMdbOnlineUserInfoEntity
#define CopySysMdbOnlineUserInfoEntity(target,source)	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->TIME=(source)->TIME;	\
			(target)->TTY=(source)->TTY;	\
			(target)->IP=(source)->IP;	\
			(target)->CONNECTIME=(source)->CONNECTIME;	\
			(target)->PID=(source)->PID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\

#endif
#ifndef CopySysMdbWebAppInfoEntity
#define CopySysMdbWebAppInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->AppName=(source)->AppName;	\
			(target)->Status=(source)->Status;	\
			(target)->Desc=(source)->Desc;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->ServletNum=(source)->ServletNum;	\
			(target)->ProcessTime=(source)->ProcessTime;	\
			(target)->RequestNum=(source)->RequestNum;	\
			(target)->ErrorNum=(source)->ErrorNum;	\
			(target)->SessionSize=(source)->SessionSize;	\
			(target)->TimeOut=(source)->TimeOut;	\
			(target)->JDBCUsage=(source)->JDBCUsage;	\
			(target)->JSPNum=(source)->JSPNum;	\

#endif
#ifndef CopySysMdbMemPoolInfoEntity
#define CopySysMdbMemPoolInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->PoolName=(source)->PoolName;	\
			(target)->Usage=(source)->Usage;	\
			(target)->committedbytes=(source)->committedbytes;	\
			(target)->initbytes=(source)->initbytes;	\
			(target)->maxbytes=(source)->maxbytes;	\
			(target)->usedbytes=(source)->usedbytes;	\
			(target)->Type=(source)->Type;	\

#endif
#ifndef CopySysMdbConnectorInfoEntity
#define CopySysMdbConnectorInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Name=(source)->Name;	\
			(target)->ThreadsCount=(source)->ThreadsCount;	\
			(target)->BusyThreadsCount=(source)->BusyThreadsCount;	\
			(target)->MaxThreads=(source)->MaxThreads;	\
			(target)->MaxSpareThreads=(source)->MaxSpareThreads;	\
			(target)->MinSpareThreads=(source)->MinSpareThreads;	\
			(target)->MaxTime=(source)->MaxTime;	\
			(target)->MaxProcTime=(source)->MaxProcTime;	\
			(target)->RequestCount=(source)->RequestCount;	\
			(target)->ErrorCount=(source)->ErrorCount;	\
			(target)->BytesReceived=(source)->BytesReceived;	\
			(target)->BytesSent=(source)->BytesSent;	\

#endif
#ifndef CopyReqQryHistoryObjectAttrEntity
#define CopyReqQryHistoryObjectAttrEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysHistoryObjectAttrEntity
#define CopySysHistoryObjectAttrEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->BeginTime=(source)->BeginTime;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->ValueType=(source)->ValueType;	\
			(target)->FirstValue=(source)->FirstValue;	\
			(target)->EndValue=(source)->EndValue;	\
			(target)->AvgValue=(source)->AvgValue;	\
			(target)->MinValue=(source)->MinValue;	\
			(target)->MaxValue=(source)->MaxValue;	\
			(target)->ValueCount=(source)->ValueCount;	\

#endif
#ifndef CopyRspQryHistoryObjectAttrEntity
#define CopyRspQryHistoryObjectAttrEntity(target,source)	\
			CopySysHistoryObjectAttrEntity(target,source);	\

#endif
#ifndef CopyRtnHistoryObjectAttrEntity
#define CopyRtnHistoryObjectAttrEntity(target,source)	\
			CopySysHistoryObjectAttrEntity(target,source);	\

#endif
#ifndef CopyReqQryFrontInfoEntity
#define CopyReqQryFrontInfoEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysFrontInfoEntity
#define CopySysFrontInfoEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->FrontId=(source)->FrontId;	\
			(target)->RspCondition=(source)->RspCondition;	\
			(target)->ReqCount=(source)->ReqCount;	\
			(target)->ReqRate=(source)->ReqRate;	\

#endif
#ifndef CopyRspQryFrontInfoEntity
#define CopyRspQryFrontInfoEntity(target,source)	\
			CopySysFrontInfoEntity(target,source);	\

#endif
#ifndef CopyRtnFrontInfoEntity
#define CopyRtnFrontInfoEntity(target,source)	\
			CopySysFrontInfoEntity(target,source);	\

#endif
#ifndef CopySysInvalidateOrderEntity
#define CopySysInvalidateOrderEntity(target,source)	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->OrderLocalID=(source)->OrderLocalID;	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ErrorMsg=(source)->ErrorMsg;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->CombOffsetFlag=(source)->CombOffsetFlag;	\
			(target)->CombHedgeFlag=(source)->CombHedgeFlag;	\
			(target)->LimitPrice=(source)->LimitPrice;	\
			(target)->VolumeTotalOriginal=(source)->VolumeTotalOriginal;	\
			(target)->TimeCondition=(source)->TimeCondition;	\
			(target)->VolumeCondition=(source)->VolumeCondition;	\
			(target)->MinVolume=(source)->MinVolume;	\

#endif
#ifndef CopySysOrderStatusEntity
#define CopySysOrderStatusEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->OrderLocalID=(source)->OrderLocalID;	\
			(target)->InsertDate=(source)->InsertDate;	\
			(target)->InsertTime=(source)->InsertTime;	\
			(target)->OrderStatus=(source)->OrderStatus;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Direction=(source)->Direction;	\
			(target)->CombOffsetFlag=(source)->CombOffsetFlag;	\
			(target)->CombHedgeFlag=(source)->CombHedgeFlag;	\
			(target)->LimitPrice=(source)->LimitPrice;	\
			(target)->VolumeTotalOriginal=(source)->VolumeTotalOriginal;	\
			(target)->TimeCondition=(source)->TimeCondition;	\
			(target)->VolumeCondition=(source)->VolumeCondition;	\
			(target)->MinVolume=(source)->MinVolume;	\

#endif
#ifndef CopySysBargainOrderEntity
#define CopySysBargainOrderEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->TradeID=(source)->TradeID;	\
			(target)->OrderSysID=(source)->OrderSysID;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->Price=(source)->Price;	\
			(target)->Volume=(source)->Volume;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ClientID=(source)->ClientID;	\

#endif
#ifndef CopySysInstPropertyEntity
#define CopySysInstPropertyEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->SettlementGroupID=(source)->SettlementGroupID;	\
			(target)->UnderlyingInstrID=(source)->UnderlyingInstrID;	\
			(target)->ProductClass=(source)->ProductClass;	\
			(target)->PositionType=(source)->PositionType;	\
			(target)->VolumeMultiple=(source)->VolumeMultiple;	\
			(target)->UnderlyingMultiple=(source)->UnderlyingMultiple;	\
			(target)->InstLifePhase=(source)->InstLifePhase;	\
			(target)->OpenDate=(source)->OpenDate;	\
			(target)->ExpireDate=(source)->ExpireDate;	\
			(target)->StartDelivDate=(source)->StartDelivDate;	\
			(target)->EndDelivDate=(source)->EndDelivDate;	\
			(target)->BasisPrice=(source)->BasisPrice;	\
			(target)->MaxMarketOrderVolume=(source)->MaxMarketOrderVolume;	\
			(target)->MinMarketOrderVolume=(source)->MinMarketOrderVolume;	\
			(target)->MaxLimitOrderVolume=(source)->MaxLimitOrderVolume;	\
			(target)->MinLimitOrderVolume=(source)->MinLimitOrderVolume;	\
			(target)->PriceTick=(source)->PriceTick;	\
			(target)->AllowDelivPersonOpen=(source)->AllowDelivPersonOpen;	\

#endif
#ifndef CopySysMarginRateEntity
#define CopySysMarginRateEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongMarginRatio=(source)->LongMarginRatio;	\
			(target)->ShortMarginRatio=(source)->ShortMarginRatio;	\

#endif
#ifndef CopySysPriceLimitEntity
#define CopySysPriceLimitEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->RoundingMode=(source)->RoundingMode;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\

#endif
#ifndef CopySysPartPosiLimitEntity
#define CopySysPartPosiLimitEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\

#endif
#ifndef CopySysClientPosiLimitEntity
#define CopySysClientPosiLimitEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\

#endif
#ifndef CopySysSpecialPosiLimitEntity
#define CopySysSpecialPosiLimitEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\

#endif
#ifndef CopySysTransactionChgEntity
#define CopySysTransactionChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->BillSN=(source)->BillSN;	\
			(target)->ParticipantAccount=(source)->ParticipantAccount;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->Amount=(source)->Amount;	\

#endif
#ifndef CopySysClientChgEntity
#define CopySysClientChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysPartClientChgEntity
#define CopySysPartClientChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysPosiLimitChgEntity
#define CopySysPosiLimitChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysClientPosiLimitChgEntity
#define CopySysClientPosiLimitChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysSpecPosiLimitChgEntity
#define CopySysSpecPosiLimitChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->StartTotalPosition=(source)->StartTotalPosition;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongPosLimit=(source)->LongPosLimit;	\
			(target)->ShortPosLimit=(source)->ShortPosLimit;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysHedgeDetailChgEntity
#define CopySysHedgeDetailChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->OperatorID=(source)->OperatorID;	\
			(target)->Time=(source)->Time;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->PosiDirection=(source)->PosiDirection;	\
			(target)->TradingVolume=(source)->TradingVolume;	\
			(target)->HedgeQuota=(source)->HedgeQuota;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysParticipantChgEntity
#define CopySysParticipantChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->MemberType=(source)->MemberType;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysMarginRateChgEntity
#define CopySysMarginRateChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->HedgeFlag=(source)->HedgeFlag;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->LongMarginRatio=(source)->LongMarginRatio;	\
			(target)->ShortMarginRatio=(source)->ShortMarginRatio;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysUserIpChgEntity
#define CopySysUserIpChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->UserID=(source)->UserID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->IPMask=(source)->IPMask;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysUserSessionEntity
#define CopySysUserSessionEntity(target,source)	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserType=(source)->UserType;	\
			(target)->LoginTime=(source)->LoginTime;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->ProtocolInfo=(source)->ProtocolInfo;	\

#endif
#ifndef CopySysMemberOffFloorSeatEntity
#define CopySysMemberOffFloorSeatEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->MemberId=(source)->MemberId;	\
			(target)->MemberSeatCode=(source)->MemberSeatCode;	\
			(target)->CommunicateType=(source)->CommunicateType;	\

#endif
#ifndef CopySysPartTradeEntity
#define CopySysPartTradeEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->TotalPositiveOrder=(source)->TotalPositiveOrder;	\
			(target)->TotalNegativeOrder=(source)->TotalNegativeOrder;	\
			(target)->TotalPositiveTrade=(source)->TotalPositiveTrade;	\
			(target)->TotalNegativeTrade=(source)->TotalNegativeTrade;	\
			(target)->TotalPositivePosi=(source)->TotalPositivePosi;	\
			(target)->TotalNegativePosi=(source)->TotalNegativePosi;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysTradepeakEntity
#define CopySysTradepeakEntity(target,source)	\
			(target)->TradepeakFlag=(source)->TradepeakFlag;	\
			(target)->PeakTime=(source)->PeakTime;	\
			(target)->InsertOrder=(source)->InsertOrder;	\
			(target)->ActionOrder=(source)->ActionOrder;	\
			(target)->InvalidOrder=(source)->InvalidOrder;	\
			(target)->TotalBusiness=(source)->TotalBusiness;	\
			(target)->TradeCount=(source)->TradeCount;	\
			(target)->TotalCount=(source)->TotalCount;	\

#endif
#ifndef CopySysPriceLimitChgEntity
#define CopySysPriceLimitChgEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->InstrumentID=(source)->InstrumentID;	\
			(target)->ValueMode=(source)->ValueMode;	\
			(target)->RoundingMode=(source)->RoundingMode;	\
			(target)->UpperLimitPrice=(source)->UpperLimitPrice;	\
			(target)->LowerLimitPrice=(source)->LowerLimitPrice;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopyReqQryInvalidateOrderEntity
#define CopyReqQryInvalidateOrderEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryInvalidateOrderEntity
#define CopyRspQryInvalidateOrderEntity(target,source)	\
			CopySysInvalidateOrderEntity(target,source);	\

#endif
#ifndef CopyRtnInvalidateOrderEntity
#define CopyRtnInvalidateOrderEntity(target,source)	\
			CopySysInvalidateOrderEntity(target,source);	\

#endif
#ifndef CopyReqQryOrderStatusEntity
#define CopyReqQryOrderStatusEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryOrderStatusEntity
#define CopyRspQryOrderStatusEntity(target,source)	\
			CopySysOrderStatusEntity(target,source);	\

#endif
#ifndef CopyRtnOrderStatusEntity
#define CopyRtnOrderStatusEntity(target,source)	\
			CopySysOrderStatusEntity(target,source);	\

#endif
#ifndef CopyReqQryBargainOrderEntity
#define CopyReqQryBargainOrderEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryBargainOrderEntity
#define CopyRspQryBargainOrderEntity(target,source)	\
			CopySysBargainOrderEntity(target,source);	\

#endif
#ifndef CopyRtnBargainOrderEntity
#define CopyRtnBargainOrderEntity(target,source)	\
			CopySysBargainOrderEntity(target,source);	\

#endif
#ifndef CopyReqQryInstPropertyEntity
#define CopyReqQryInstPropertyEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->EndDate=(source)->EndDate;	\

#endif
#ifndef CopyRspQryInstPropertyEntity
#define CopyRspQryInstPropertyEntity(target,source)	\
			CopySysInstPropertyEntity(target,source);	\

#endif
#ifndef CopyRtnInstPropertyEntity
#define CopyRtnInstPropertyEntity(target,source)	\
			CopySysInstPropertyEntity(target,source);	\

#endif
#ifndef CopyReqQryMarginRateEntity
#define CopyReqQryMarginRateEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->EndDate=(source)->EndDate;	\

#endif
#ifndef CopyRspQryMarginRateEntity
#define CopyRspQryMarginRateEntity(target,source)	\
			CopySysMarginRateEntity(target,source);	\

#endif
#ifndef CopyRtnMarginRateEntity
#define CopyRtnMarginRateEntity(target,source)	\
			CopySysMarginRateEntity(target,source);	\

#endif
#ifndef CopyReqQryPriceLimitEntity
#define CopyReqQryPriceLimitEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->EndDate=(source)->EndDate;	\

#endif
#ifndef CopyRspQryPriceLimitEntity
#define CopyRspQryPriceLimitEntity(target,source)	\
			CopySysPriceLimitEntity(target,source);	\

#endif
#ifndef CopyRtnPriceLimitEntity
#define CopyRtnPriceLimitEntity(target,source)	\
			CopySysPriceLimitEntity(target,source);	\

#endif
#ifndef CopyReqQryPartPosiLimitEntity
#define CopyReqQryPartPosiLimitEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->EndDate=(source)->EndDate;	\

#endif
#ifndef CopyRspQryPartPosiLimitEntity
#define CopyRspQryPartPosiLimitEntity(target,source)	\
			CopySysPartPosiLimitEntity(target,source);	\

#endif
#ifndef CopyRtnPartPosiLimitEntity
#define CopyRtnPartPosiLimitEntity(target,source)	\
			CopySysPartPosiLimitEntity(target,source);	\

#endif
#ifndef CopyReqQryClientPosiLimitEntity
#define CopyReqQryClientPosiLimitEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->EndDate=(source)->EndDate;	\

#endif
#ifndef CopyRspQryClientPosiLimitEntity
#define CopyRspQryClientPosiLimitEntity(target,source)	\
			CopySysClientPosiLimitEntity(target,source);	\

#endif
#ifndef CopyRtnClientPosiLimitEntity
#define CopyRtnClientPosiLimitEntity(target,source)	\
			CopySysClientPosiLimitEntity(target,source);	\

#endif
#ifndef CopyReqQrySpecialPosiLimitEntity
#define CopyReqQrySpecialPosiLimitEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->EndDate=(source)->EndDate;	\

#endif
#ifndef CopyRspQrySpecialPosiLimitEntity
#define CopyRspQrySpecialPosiLimitEntity(target,source)	\
			CopySysSpecialPosiLimitEntity(target,source);	\

#endif
#ifndef CopyRtnSpecialPosiLimitEntity
#define CopyRtnSpecialPosiLimitEntity(target,source)	\
			CopySysSpecialPosiLimitEntity(target,source);	\

#endif
#ifndef CopyReqQryTransactionChgEntity
#define CopyReqQryTransactionChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryTransactionChgEntity
#define CopyRspQryTransactionChgEntity(target,source)	\
			CopySysTransactionChgEntity(target,source);	\

#endif
#ifndef CopyRtnTransactionChgEntity
#define CopyRtnTransactionChgEntity(target,source)	\
			CopySysTransactionChgEntity(target,source);	\

#endif
#ifndef CopyReqQryClientChgEntity
#define CopyReqQryClientChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryClientChgEntity
#define CopyRspQryClientChgEntity(target,source)	\
			CopySysClientChgEntity(target,source);	\

#endif
#ifndef CopyRtnClientChgEntity
#define CopyRtnClientChgEntity(target,source)	\
			CopySysClientChgEntity(target,source);	\

#endif
#ifndef CopyReqQryPartClientChgEntity
#define CopyReqQryPartClientChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryPartClientChgEntity
#define CopyRspQryPartClientChgEntity(target,source)	\
			CopySysPartClientChgEntity(target,source);	\

#endif
#ifndef CopyRtnPartClientChgEntity
#define CopyRtnPartClientChgEntity(target,source)	\
			CopySysPartClientChgEntity(target,source);	\

#endif
#ifndef CopyReqQryPosiLimitChgEntity
#define CopyReqQryPosiLimitChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryPosiLimitChgEntity
#define CopyRspQryPosiLimitChgEntity(target,source)	\
			CopySysPosiLimitChgEntity(target,source);	\

#endif
#ifndef CopyRtnPosiLimitChgEntity
#define CopyRtnPosiLimitChgEntity(target,source)	\
			CopySysPosiLimitChgEntity(target,source);	\

#endif
#ifndef CopyReqQryClientPosiLimitChgEntity
#define CopyReqQryClientPosiLimitChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryClientPosiLimitChgEntity
#define CopyRspQryClientPosiLimitChgEntity(target,source)	\
			CopySysClientPosiLimitChgEntity(target,source);	\

#endif
#ifndef CopyRtnClientPosiLimitChgEntity
#define CopyRtnClientPosiLimitChgEntity(target,source)	\
			CopySysClientPosiLimitChgEntity(target,source);	\

#endif
#ifndef CopyReqQrySpecPosiLimitChgEntity
#define CopyReqQrySpecPosiLimitChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQrySpecPosiLimitChgEntity
#define CopyRspQrySpecPosiLimitChgEntity(target,source)	\
			CopySysSpecPosiLimitChgEntity(target,source);	\

#endif
#ifndef CopyRtnSpecPosiLimitChgEntity
#define CopyRtnSpecPosiLimitChgEntity(target,source)	\
			CopySysSpecPosiLimitChgEntity(target,source);	\

#endif
#ifndef CopyReqQryHedgeDetailChgEntity
#define CopyReqQryHedgeDetailChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryHedgeDetailChgEntity
#define CopyRspQryHedgeDetailChgEntity(target,source)	\
			CopySysHedgeDetailChgEntity(target,source);	\

#endif
#ifndef CopyRtnHedgeDetailChgEntity
#define CopyRtnHedgeDetailChgEntity(target,source)	\
			CopySysHedgeDetailChgEntity(target,source);	\

#endif
#ifndef CopyReqQryParticipantChgEntity
#define CopyReqQryParticipantChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryParticipantChgEntity
#define CopyRspQryParticipantChgEntity(target,source)	\
			CopySysParticipantChgEntity(target,source);	\

#endif
#ifndef CopyRtnParticipantChgEntity
#define CopyRtnParticipantChgEntity(target,source)	\
			CopySysParticipantChgEntity(target,source);	\

#endif
#ifndef CopyReqQryMarginRateChgEntity
#define CopyReqQryMarginRateChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryMarginRateChgEntity
#define CopyRspQryMarginRateChgEntity(target,source)	\
			CopySysMarginRateChgEntity(target,source);	\

#endif
#ifndef CopyRtnMarginRateChgEntity
#define CopyRtnMarginRateChgEntity(target,source)	\
			CopySysMarginRateChgEntity(target,source);	\

#endif
#ifndef CopyRtnPriceLimitChgEntity
#define CopyRtnPriceLimitChgEntity(target,source)	\
			CopySysPriceLimitChgEntity(target,source);	\

#endif
#ifndef CopyReqQryUserIpChgEntity
#define CopyReqQryUserIpChgEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryUserIpChgEntity
#define CopyRspQryUserIpChgEntity(target,source)	\
			CopySysUserIpChgEntity(target,source);	\

#endif
#ifndef CopyRtnUserIpChgEntity
#define CopyRtnUserIpChgEntity(target,source)	\
			CopySysUserIpChgEntity(target,source);	\

#endif
#ifndef CopyReqQryPartTradeEntity
#define CopyReqQryPartTradeEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryPartTradeEntity
#define CopyRspQryPartTradeEntity(target,source)	\
			CopySysPartTradeEntity(target,source);	\

#endif
#ifndef CopyReqQryTradepeakEntity
#define CopyReqQryTradepeakEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->TradepeakFlag=(source)->TradepeakFlag;	\

#endif
#ifndef CopyRspQryTradepeakEntity
#define CopyRspQryTradepeakEntity(target,source)	\
			CopySysTradepeakEntity(target,source);	\

#endif
#ifndef CopyReqQrySysUserLoginEntity
#define CopyReqQrySysUserLoginEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->Password=(source)->Password;	\
			(target)->VersionID=(source)->VersionID;	\

#endif
#ifndef CopyRspQrySysUserLoginEntity
#define CopyRspQrySysUserLoginEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->LoginTime=(source)->LoginTime;	\
			(target)->Privilege=(source)->Privilege;	\
			(target)->VersionFlag=(source)->VersionFlag;	\

#endif
#ifndef CopyReqQrySysUserLogoutEntity
#define CopyReqQrySysUserLogoutEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyRspQrySysUserLogoutEntity
#define CopyRspQrySysUserLogoutEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyReqQrySysUserPasswordUpdateEntity
#define CopyReqQrySysUserPasswordUpdateEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->OldPassword=(source)->OldPassword;	\
			(target)->NewPassword=(source)->NewPassword;	\

#endif
#ifndef CopyRspQrySysUserPasswordUpdateEntity
#define CopyRspQrySysUserPasswordUpdateEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->PasswordChgMsg=(source)->PasswordChgMsg;	\

#endif
#ifndef CopyReqQrySysUserRegisterEntity
#define CopyReqQrySysUserRegisterEntity(target,source)	\
			CopySysRegisterUserInfoEntity(target,source);	\

#endif
#ifndef CopyRspQrySysUserRegisterEntity
#define CopyRspQrySysUserRegisterEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->Privilege=(source)->Privilege;	\

#endif
#ifndef CopyRtnSysUserEntity
#define CopyRtnSysUserEntity(target,source)	\
			CopySysRegisterUserInfoEntity(target,source);	\

#endif
#ifndef CopyReqQrySysUserDeleteEntity
#define CopyReqQrySysUserDeleteEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopyRspQrySysUserDeleteEntity
#define CopyRspQrySysUserDeleteEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\

#endif
#ifndef CopySysRegisterUserInfoEntity
#define CopySysRegisterUserInfoEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserName=(source)->UserName;	\
			(target)->UserInfo=(source)->UserInfo;	\
			(target)->Password=(source)->Password;	\
			(target)->Privilege=(source)->Privilege;	\
			(target)->EMail=(source)->EMail;	\
			(target)->EMailFlag=(source)->EMailFlag;	\
			(target)->HomePhone=(source)->HomePhone;	\
			(target)->HomePhoneFlag=(source)->HomePhoneFlag;	\
			(target)->MobilePhone=(source)->MobilePhone;	\
			(target)->MobilePhoneFlag=(source)->MobilePhoneFlag;	\

#endif
#ifndef CopySysUserActionInfoEntity
#define CopySysUserActionInfoEntity(target,source)	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserActionType=(source)->UserActionType;	\
			(target)->UserActionResult=(source)->UserActionResult;	\

#endif
#ifndef CopyReqQryParticipantInitEntity
#define CopyReqQryParticipantInitEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyReqQryUserInitEntity
#define CopyReqQryUserInitEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysParticipantInitEntity
#define CopySysParticipantInitEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->ParticipantAbbr=(source)->ParticipantAbbr;	\
			(target)->MemberType=(source)->MemberType;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysUserInitEntity
#define CopySysUserInitEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->UserType=(source)->UserType;	\
			(target)->Password=(source)->Password;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySysClientInitEntity
#define CopySysClientInitEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->IdentifiedCardType=(source)->IdentifiedCardType;	\
			(target)->IdentifiedCardNo=(source)->IdentifiedCardNo;	\
			(target)->TradingRole=(source)->TradingRole;	\
			(target)->ClientType=(source)->ClientType;	\
			(target)->IsActive=(source)->IsActive;	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopyReqQryTradeLogEntity
#define CopyReqQryTradeLogEntity(target,source)	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->StartParticipant=(source)->StartParticipant;	\
			(target)->EndParticipant=(source)->EndParticipant;	\
			(target)->StartUser=(source)->StartUser;	\
			(target)->EndUser=(source)->EndUser;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->StartSessionID=(source)->StartSessionID;	\
			(target)->EndSessionID=(source)->EndSessionID;	\
			(target)->IPFlag=(source)->IPFlag;	\
			(target)->PartFlag=(source)->PartFlag;	\
			(target)->UserIDFlag=(source)->UserIDFlag;	\
			(target)->TimeFlag=(source)->TimeFlag;	\
			(target)->FrontFlag=(source)->FrontFlag;	\
			(target)->SessionFlag=(source)->SessionFlag;	\

#endif
#ifndef CopySysTradeLogEntity
#define CopySysTradeLogEntity(target,source)	\
			(target)->bFlag=(source)->bFlag;	\
			(target)->TradeLogStr=(source)->TradeLogStr;	\

#endif
#ifndef CopyRspQryTradeLogEntity
#define CopyRspQryTradeLogEntity(target,source)	\
			CopySysTradeLogEntity(target,source);	\

#endif
#ifndef CopyRtnTradeLogEntity
#define CopyRtnTradeLogEntity(target,source)	\
			CopySysTradeLogEntity(target,source);	\

#endif
#ifndef CopyReqQryTradeUserLoginInfoEntity
#define CopyReqQryTradeUserLoginInfoEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysTradeUserLoginInfoEntity
#define CopySysTradeUserLoginInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->ProtocolInfo=(source)->ProtocolInfo;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->UserType=(source)->UserType;	\
			(target)->AccessType=(source)->AccessType;	\
			(target)->ActionDate=(source)->ActionDate;	\
			(target)->ActionTime=(source)->ActionTime;	\
			(target)->ActionFlag=(source)->ActionFlag;	\
			(target)->DataCenter=(source)->DataCenter;	\

#endif
#ifndef CopyRspQryTradeUserLoginInfoEntity
#define CopyRspQryTradeUserLoginInfoEntity(target,source)	\
			CopySysTradeUserLoginInfoEntity(target,source);	\

#endif
#ifndef CopyRtnTradeUserLoginInfoEntity
#define CopyRtnTradeUserLoginInfoEntity(target,source)	\
			CopySysTradeUserLoginInfoEntity(target,source);	\

#endif
#ifndef CopySysUpdateSysConfigEntity
#define CopySysUpdateSysConfigEntity(target,source)	\
			(target)->UpdateType=(source)->UpdateType;	\
			(target)->OldValue=(source)->OldValue;	\
			(target)->NewValue=(source)->NewValue;	\
			(target)->Standby=(source)->Standby;	\

#endif
#ifndef CopyRtnUpdateSysConfigEntity
#define CopyRtnUpdateSysConfigEntity(target,source)	\
			CopySysUpdateSysConfigEntity(target,source);	\

#endif
#ifndef CopySysFileAccessInfoEntity
#define CopySysFileAccessInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->FileSize=(source)->FileSize;	\
			(target)->FileTime=(source)->FileTime;	\

#endif
#ifndef CopyReqQryHistoryCpuInfoEntity
#define CopyReqQryHistoryCpuInfoEntity(target,source)	\
			CopyReqQryTopCpuInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryHistoryCpuInfoEntity
#define CopyRspQryHistoryCpuInfoEntity(target,source)	\
			CopyRspQryTopCpuInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryHistoryMemInfoEntity
#define CopyReqQryHistoryMemInfoEntity(target,source)	\
			CopyReqQryTopMemInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryHistoryMemInfoEntity
#define CopyRspQryHistoryMemInfoEntity(target,source)	\
			CopyRspQryTopMemInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryHistoryNetworkInfoEntity
#define CopyReqQryHistoryNetworkInfoEntity(target,source)	\
			CopyReqQryNetworkInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryHistoryNetworkInfoEntity
#define CopyRspQryHistoryNetworkInfoEntity(target,source)	\
			CopyRspQryNetworkInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryMonitorOnlineUserEntity
#define CopyReqQryMonitorOnlineUserEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopyRspQryMonitorOnlineUserEntity
#define CopyRspQryMonitorOnlineUserEntity(target,source)	\
			(target)->UserID=(source)->UserID;	\
			(target)->IPAddress=(source)->IPAddress;	\

#endif
#ifndef CopyReqQryFrontStatEntity
#define CopyReqQryFrontStatEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysFrontStatEntity
#define CopySysFrontStatEntity(target,source)	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->PositiveOrder=(source)->PositiveOrder;	\
			(target)->NegativeOrder=(source)->NegativeOrder;	\
			(target)->TotalPositiveOrder=(source)->TotalPositiveOrder;	\
			(target)->TotalNegativeOrder=(source)->TotalNegativeOrder;	\
			(target)->OrderAction=(source)->OrderAction;	\
			(target)->TotalOrderAction=(source)->TotalOrderAction;	\

#endif
#ifndef CopyRspQryFrontStatEntity
#define CopyRspQryFrontStatEntity(target,source)	\
			CopySysFrontStatEntity(target,source);	\

#endif
#ifndef CopyRtnSysTimeSyncEntity
#define CopyRtnSysTimeSyncEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\

#endif
#ifndef CopyRtnDataCenterChgEntity
#define CopyRtnDataCenterChgEntity(target,source)	\
			(target)->DataCenterID=(source)->DataCenterID;	\

#endif
#ifndef CopyReqQryHistoryTradePeakEntity
#define CopyReqQryHistoryTradePeakEntity(target,source)	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysHistoryTradePeakEntity
#define CopySysHistoryTradePeakEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->AttrValue=(source)->AttrValue;	\
			(target)->RltAttrType=(source)->RltAttrType;	\
			(target)->RltAttrValue=(source)->RltAttrValue;	\
			(target)->MaxMonDate=(source)->MaxMonDate;	\
			(target)->MaxMonTime=(source)->MaxMonTime;	\
			(target)->MaxAttrValue=(source)->MaxAttrValue;	\
			(target)->MaxRltAttrValue=(source)->MaxRltAttrValue;	\
			(target)->OldMonDate=(source)->OldMonDate;	\
			(target)->OldMonTime=(source)->OldMonTime;	\
			(target)->OldAttrValue=(source)->OldAttrValue;	\
			(target)->OldRltAttrValue=(source)->OldRltAttrValue;	\

#endif
#ifndef CopyRspQryHistoryTradePeakEntity
#define CopyRspQryHistoryTradePeakEntity(target,source)	\
			CopySysHistoryTradePeakEntity(target,source);	\

#endif
#ifndef CopyRtnHistoryTradePeakEntity
#define CopyRtnHistoryTradePeakEntity(target,source)	\
			CopySysHistoryTradePeakEntity(target,source);	\

#endif
#ifndef CopySysTradeDayChangeEntity
#define CopySysTradeDayChangeEntity(target,source)	\
			(target)->ChangeType=(source)->ChangeType;	\
			(target)->OldDate=(source)->OldDate;	\
			(target)->NewDate=(source)->NewDate;	\

#endif
#ifndef CopyReqQryTradeDayChangeEntity
#define CopyReqQryTradeDayChangeEntity(target,source)	\
			CopySysTradeDayChangeEntity(target,source);	\

#endif
#ifndef CopyRspQryTradeDayChangeEntity
#define CopyRspQryTradeDayChangeEntity(target,source)	\
			CopySysTradeDayChangeEntity(target,source);	\

#endif
#ifndef CopyReqQryTomcatInfoEntity
#define CopyReqQryTomcatInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopySysWebAppInfoEntity
#define CopySysWebAppInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->AppName=(source)->AppName;	\
			(target)->Status=(source)->Status;	\
			(target)->Desc=(source)->Desc;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->ServletNum=(source)->ServletNum;	\
			(target)->ProcessTime=(source)->ProcessTime;	\
			(target)->RequestNum=(source)->RequestNum;	\
			(target)->ErrorNum=(source)->ErrorNum;	\
			(target)->SessionSize=(source)->SessionSize;	\
			(target)->TimeOut=(source)->TimeOut;	\
			(target)->JDBCUsage=(source)->JDBCUsage;	\
			(target)->JSPNum=(source)->JSPNum;	\

#endif
#ifndef CopyRspQryWebAppInfoEntity
#define CopyRspQryWebAppInfoEntity(target,source)	\
			CopySysWebAppInfoEntity(target,source);	\

#endif
#ifndef CopyRtnWebAppInfoEntity
#define CopyRtnWebAppInfoEntity(target,source)	\
			CopySysWebAppInfoEntity(target,source);	\

#endif
#ifndef CopySysServletInfoEntity
#define CopySysServletInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Name=(source)->Name;	\
			(target)->LoadTime=(source)->LoadTime;	\
			(target)->RequestNum=(source)->RequestNum;	\
			(target)->RequestErrNum=(source)->RequestErrNum;	\
			(target)->ProcessTime=(source)->ProcessTime;	\
			(target)->MixTime=(source)->MixTime;	\
			(target)->MaxTime=(source)->MaxTime;	\

#endif
#ifndef CopyRspQryServletInfoEntity
#define CopyRspQryServletInfoEntity(target,source)	\
			CopySysServletInfoEntity(target,source);	\

#endif
#ifndef CopyRtnServletInfoEntity
#define CopyRtnServletInfoEntity(target,source)	\
			CopySysServletInfoEntity(target,source);	\

#endif
#ifndef CopySysFileInfoEntity
#define CopySysFileInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->PathName=(source)->PathName;	\
			(target)->FileSize=(source)->FileSize;	\
			(target)->LastModDate=(source)->LastModDate;	\
			(target)->FileType=(source)->FileType;	\

#endif
#ifndef CopyRspQryFileInfoEntity
#define CopyRspQryFileInfoEntity(target,source)	\
			CopySysFileInfoEntity(target,source);	\

#endif
#ifndef CopyRtnFileInfoEntity
#define CopyRtnFileInfoEntity(target,source)	\
			CopySysFileInfoEntity(target,source);	\

#endif
#ifndef CopySysSessionInfoEntity
#define CopySysSessionInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->SessionID=(source)->SessionID;	\
			(target)->SessionName=(source)->SessionName;	\
			(target)->RemoteIP=(source)->RemoteIP;	\
			(target)->BeginTime=(source)->BeginTime;	\
			(target)->LatestTime=(source)->LatestTime;	\
			(target)->MaxIdleTime=(source)->MaxIdleTime;	\

#endif
#ifndef CopyRspQrySessionInfoEntity
#define CopyRspQrySessionInfoEntity(target,source)	\
			CopySysSessionInfoEntity(target,source);	\

#endif
#ifndef CopyRtnSessionInfoEntity
#define CopyRtnSessionInfoEntity(target,source)	\
			CopySysSessionInfoEntity(target,source);	\

#endif
#ifndef CopySysJDBCInfoEntity
#define CopySysJDBCInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->AppName=(source)->AppName;	\
			(target)->Name=(source)->Name;	\
			(target)->Usage=(source)->Usage;	\
			(target)->ConnNumMax=(source)->ConnNumMax;	\
			(target)->ConnNumFree=(source)->ConnNumFree;	\
			(target)->ConnNumUnRU=(source)->ConnNumUnRU;	\
			(target)->ConnNumRU=(source)->ConnNumRU;	\
			(target)->UserName=(source)->UserName;	\
			(target)->Type=(source)->Type;	\
			(target)->URL=(source)->URL;	\

#endif
#ifndef CopyRspQryJDBCInfoEntity
#define CopyRspQryJDBCInfoEntity(target,source)	\
			CopySysJDBCInfoEntity(target,source);	\

#endif
#ifndef CopyRtnJDBCInfoEntity
#define CopyRtnJDBCInfoEntity(target,source)	\
			CopySysJDBCInfoEntity(target,source);	\

#endif
#ifndef CopySysThreadInfoEntity
#define CopySysThreadInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Name=(source)->Name;	\
			(target)->ThreadNum=(source)->ThreadNum;	\
			(target)->ThreadStatus=(source)->ThreadStatus;	\
			(target)->InNative=(source)->InNative;	\
			(target)->Suspended=(source)->Suspended;	\
			(target)->BlockCount=(source)->BlockCount;	\
			(target)->WaitCount=(source)->WaitCount;	\
			(target)->CpuTime=(source)->CpuTime;	\
			(target)->UserTime=(source)->UserTime;	\

#endif
#ifndef CopyRspQryThreadInfoEntity
#define CopyRspQryThreadInfoEntity(target,source)	\
			CopySysThreadInfoEntity(target,source);	\

#endif
#ifndef CopyRtnThreadInfoEntity
#define CopyRtnThreadInfoEntity(target,source)	\
			CopySysThreadInfoEntity(target,source);	\

#endif
#ifndef CopySysVMInfoEntity
#define CopySysVMInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Name=(source)->Name;	\
			(target)->VmName=(source)->VmName;	\
			(target)->VmVendor=(source)->VmVendor;	\
			(target)->VmVersion=(source)->VmVersion;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->BootClassPath=(source)->BootClassPath;	\
			(target)->ClassPath=(source)->ClassPath;	\
			(target)->LibraryPath=(source)->LibraryPath;	\
			(target)->Arguments=(source)->Arguments;	\

#endif
#ifndef CopyReqQryVMInfoEntity
#define CopyReqQryVMInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyRspQryVMInfoEntity
#define CopyRspQryVMInfoEntity(target,source)	\
			CopySysVMInfoEntity(target,source);	\

#endif
#ifndef CopyRtnVMInfoEntity
#define CopyRtnVMInfoEntity(target,source)	\
			CopySysVMInfoEntity(target,source);	\

#endif
#ifndef CopySysPropertyInfoEntity
#define CopySysPropertyInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Property=(source)->Property;	\
			(target)->ClipFlag=(source)->ClipFlag;	\
			(target)->Value=(source)->Value;	\

#endif
#ifndef CopyReqQryPropertyInfoEntity
#define CopyReqQryPropertyInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyRspQryPropertyInfoEntity
#define CopyRspQryPropertyInfoEntity(target,source)	\
			CopySysPropertyInfoEntity(target,source);	\

#endif
#ifndef CopyRtnPropertyInfoEntity
#define CopyRtnPropertyInfoEntity(target,source)	\
			CopySysPropertyInfoEntity(target,source);	\

#endif
#ifndef CopySysMemPoolInfoEntity
#define CopySysMemPoolInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->PoolName=(source)->PoolName;	\
			(target)->Usage=(source)->Usage;	\
			(target)->committedbytes=(source)->committedbytes;	\
			(target)->initbytes=(source)->initbytes;	\
			(target)->maxbytes=(source)->maxbytes;	\
			(target)->usedbytes=(source)->usedbytes;	\
			(target)->Type=(source)->Type;	\

#endif
#ifndef CopyReqQryMemPoolInfoEntity
#define CopyReqQryMemPoolInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyRspQryMemPoolInfoEntity
#define CopyRspQryMemPoolInfoEntity(target,source)	\
			CopySysMemPoolInfoEntity(target,source);	\

#endif
#ifndef CopyRtnMemPoolInfoEntity
#define CopyRtnMemPoolInfoEntity(target,source)	\
			CopySysMemPoolInfoEntity(target,source);	\

#endif
#ifndef CopySysFileContentInfoEntity
#define CopySysFileContentInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->FileName=(source)->FileName;	\
			(target)->FileContent=(source)->FileContent;	\

#endif
#ifndef CopyReqQryFileContentInfoEntity
#define CopyReqQryFileContentInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyRspQryFileContentInfoEntity
#define CopyRspQryFileContentInfoEntity(target,source)	\
			CopySysFileContentInfoEntity(target,source);	\

#endif
#ifndef CopyRtnFileContentInfoEntity
#define CopyRtnFileContentInfoEntity(target,source)	\
			CopySysFileContentInfoEntity(target,source);	\

#endif
#ifndef CopySysConnectionInfoEntity
#define CopySysConnectionInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ServiceName=(source)->ServiceName;	\
			(target)->Stage=(source)->Stage;	\
			(target)->RequestCount=(source)->RequestCount;	\
			(target)->ErrorCount=(source)->ErrorCount;	\
			(target)->ProcTime=(source)->ProcTime;	\
			(target)->BytesReceived=(source)->BytesReceived;	\
			(target)->BytesSent=(source)->BytesSent;	\
			(target)->RemoteIP=(source)->RemoteIP;	\
			(target)->MaxAccessURI=(source)->MaxAccessURI;	\

#endif
#ifndef CopyReqQryConnectionInfoEntity
#define CopyReqQryConnectionInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyRspQryConnectionInfoEntity
#define CopyRspQryConnectionInfoEntity(target,source)	\
			CopySysConnectionInfoEntity(target,source);	\

#endif
#ifndef CopyRtnConnectionInfoEntity
#define CopyRtnConnectionInfoEntity(target,source)	\
			CopySysConnectionInfoEntity(target,source);	\

#endif
#ifndef CopySysConnectorInfoEntity
#define CopySysConnectorInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Name=(source)->Name;	\
			(target)->ThreadsCount=(source)->ThreadsCount;	\
			(target)->BusyThreadsCount=(source)->BusyThreadsCount;	\
			(target)->MaxThreads=(source)->MaxThreads;	\
			(target)->MaxSpareThreads=(source)->MaxSpareThreads;	\
			(target)->MinSpareThreads=(source)->MinSpareThreads;	\
			(target)->MaxTime=(source)->MaxTime;	\
			(target)->MaxProcTime=(source)->MaxProcTime;	\
			(target)->RequestCount=(source)->RequestCount;	\
			(target)->ErrorCount=(source)->ErrorCount;	\
			(target)->BytesReceived=(source)->BytesReceived;	\
			(target)->BytesSent=(source)->BytesSent;	\

#endif
#ifndef CopyReqQryConnectorInfoEntity
#define CopyReqQryConnectorInfoEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyRspQryConnectorInfoEntity
#define CopyRspQryConnectorInfoEntity(target,source)	\
			CopySysConnectorInfoEntity(target,source);	\

#endif
#ifndef CopyRtnConnectorInfoEntity
#define CopyRtnConnectorInfoEntity(target,source)	\
			CopySysConnectorInfoEntity(target,source);	\

#endif
#ifndef CopySysGeneralFieldEntity
#define CopySysGeneralFieldEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->SubObjectID=(source)->SubObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->Content=(source)->Content;	\

#endif
#ifndef CopyReqQryGetFileEntity
#define CopyReqQryGetFileEntity(target,source)	\
			(target)->FileName=(source)->FileName;	\
			(target)->Version=(source)->Version;	\
			(target)->Offset=(source)->Offset;	\

#endif
#ifndef CopyRspQryGetFileEntity
#define CopyRspQryGetFileEntity(target,source)	\
			(target)->FileName=(source)->FileName;	\
			(target)->Version=(source)->Version;	\
			(target)->Offset=(source)->Offset;	\
			(target)->Length=(source)->Length;	\
			(target)->Comment=(source)->Comment;	\

#endif
#ifndef CopyReqQryWarningQueryEntity
#define CopyReqQryWarningQueryEntity(target,source)	\
			(target)->EvendID=(source)->EvendID;	\

#endif
#ifndef CopySysWarningQueryEntity
#define CopySysWarningQueryEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->EvendID=(source)->EvendID;	\
			(target)->DBQueryResult=(source)->DBQueryResult;	\

#endif
#ifndef CopyRspQryWarningQueryEntity
#define CopyRspQryWarningQueryEntity(target,source)	\
			CopySysWarningQueryEntity(target,source);	\

#endif
#ifndef CopyRtnWarningQueryEntity
#define CopyRtnWarningQueryEntity(target,source)	\
			CopySysWarningQueryEntity(target,source);	\

#endif
#ifndef CopyReqQryWebVisitEntity
#define CopyReqQryWebVisitEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->BeginDate=(source)->BeginDate;	\
			(target)->BeginTime=(source)->BeginTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysWarningActiveChangeEntity
#define CopySysWarningActiveChangeEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->WarningActive=(source)->WarningActive;	\

#endif
#ifndef CopyReqQryWarningActiveChangeEntity
#define CopyReqQryWarningActiveChangeEntity(target,source)	\
			CopySysWarningActiveChangeEntity(target,source);	\

#endif
#ifndef CopyRspQryWarningActiveChangeEntity
#define CopyRspQryWarningActiveChangeEntity(target,source)	\
			CopySysWarningActiveChangeEntity(target,source);	\

#endif
#ifndef CopyRtnWarningActiveChangeEntity
#define CopyRtnWarningActiveChangeEntity(target,source)	\
			CopySysWarningActiveChangeEntity(target,source);	\

#endif
#ifndef CopySysTradeUserLoginStatEntity
#define CopySysTradeUserLoginStatEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->FrontId=(source)->FrontId;	\

#endif
#ifndef CopyReqQryTradeUserLoginStatEntity
#define CopyReqQryTradeUserLoginStatEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\

#endif
#ifndef CopyRspQryTradeUserLoginStatEntity
#define CopyRspQryTradeUserLoginStatEntity(target,source)	\
			CopySysTradeUserLoginStatEntity(target,source);	\

#endif
#ifndef CopySysTradeFrontOrderRttStatEntity
#define CopySysTradeFrontOrderRttStatEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->OrderCount=(source)->OrderCount;	\
			(target)->OrderRttSum=(source)->OrderRttSum;	\
			(target)->OrderMaxRtt=(source)->OrderMaxRtt;	\
			(target)->OrderMinRtt=(source)->OrderMinRtt;	\
			(target)->OrderRttSqu=(source)->OrderRttSqu;	\
			(target)->OrderRttCutDistrib=(source)->OrderRttCutDistrib;	\

#endif
#ifndef CopyReqQryTradeFrontOrderRttStatEntity
#define CopyReqQryTradeFrontOrderRttStatEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonStartTime=(source)->MonStartTime;	\
			(target)->MonEndTime=(source)->MonEndTime;	\

#endif
#ifndef CopyRspQryTradeFrontOrderRttStatEntity
#define CopyRspQryTradeFrontOrderRttStatEntity(target,source)	\
			CopySysTradeFrontOrderRttStatEntity(target,source);	\

#endif
#ifndef CopyRtnTradeFrontOrderRttStatEntity
#define CopyRtnTradeFrontOrderRttStatEntity(target,source)	\
			CopySysTradeFrontOrderRttStatEntity(target,source);	\

#endif
#ifndef CopySysMdbTradeFrontOrderRttStatEntity
#define CopySysMdbTradeFrontOrderRttStatEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			CopySysTradeFrontOrderRttStatEntity(target,source);	\

#endif
#ifndef CopySysTradeOrderRttCutLineEntity
#define CopySysTradeOrderRttCutLineEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->UserName=(source)->UserName;	\
			(target)->OrderRttCutLine=(source)->OrderRttCutLine;	\
			(target)->OrderRttWidth=(source)->OrderRttWidth;	\

#endif
#ifndef CopyReqQryTradeOrderRttCutLineEntity
#define CopyReqQryTradeOrderRttCutLineEntity(target,source)	\
			CopySysTradeOrderRttCutLineEntity(target,source);	\

#endif
#ifndef CopyRspQryTradeOrderRttCutLineEntity
#define CopyRspQryTradeOrderRttCutLineEntity(target,source)	\
			CopySysTradeOrderRttCutLineEntity(target,source);	\

#endif
#ifndef CopyRtnTradeOrderRttCutLineEntity
#define CopyRtnTradeOrderRttCutLineEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->OrderRttCutLine=(source)->OrderRttCutLine;	\

#endif
#ifndef CopySysParticTradeOrderStatesEntity
#define CopySysParticTradeOrderStatesEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->StaticWidth=(source)->StaticWidth;	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->OrderCount=(source)->OrderCount;	\
			(target)->CancleCount=(source)->CancleCount;	\
			(target)->QueryCount=(source)->QueryCount;	\
			(target)->TradeCount=(source)->TradeCount;	\
			(target)->TradeMoney=(source)->TradeMoney;	\
			(target)->OrderCntMax=(source)->OrderCntMax;	\
			(target)->CancleCntMax=(source)->CancleCntMax;	\
			(target)->QueryCntMax=(source)->QueryCntMax;	\
			(target)->TradeCntMax=(source)->TradeCntMax;	\
			(target)->TradeMoneyMax=(source)->TradeMoneyMax;	\

#endif
#ifndef CopyReqQryParticTradeOrderStatesEntity
#define CopyReqQryParticTradeOrderStatesEntity(target,source)	\
			(target)->ParticipantID=(source)->ParticipantID;	\
			(target)->UserID=(source)->UserID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonStartTime=(source)->MonStartTime;	\
			(target)->MonEndTime=(source)->MonEndTime;	\

#endif
#ifndef CopyRspQryParticTradeOrderStatesEntity
#define CopyRspQryParticTradeOrderStatesEntity(target,source)	\
			CopySysParticTradeOrderStatesEntity(target,source);	\

#endif
#ifndef CopyRtnParticTradeOrderStatesEntity
#define CopyRtnParticTradeOrderStatesEntity(target,source)	\
			CopySysParticTradeOrderStatesEntity(target,source);	\

#endif
#ifndef CopyRouterInfoEntity
#define CopyRouterInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Dev=(source)->Dev;	\
			(target)->Destination=(source)->Destination;	\
			(target)->Gateway=(source)->Gateway;	\
			(target)->Mask=(source)->Mask;	\
			(target)->Flag=(source)->Flag;	\
			(target)->RefCnt=(source)->RefCnt;	\
			(target)->Use=(source)->Use;	\
			(target)->Metric=(source)->Metric;	\
			(target)->Mtu=(source)->Mtu;	\
			(target)->Win=(source)->Win;	\
			(target)->Rtt=(source)->Rtt;	\

#endif
#ifndef CopyReqQryRouterInfoEntity
#define CopyReqQryRouterInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryRouterInfoEntity
#define CopyRspQryRouterInfoEntity(target,source)	\
			CopyRouterInfoEntity(target,source);	\

#endif
#ifndef CopyRtnRouterInfoEntity
#define CopyRtnRouterInfoEntity(target,source)	\
			CopyRouterInfoEntity(target,source);	\

#endif
#ifndef CopySysMdbRouterInfoEntity
#define CopySysMdbRouterInfoEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			CopyRouterInfoEntity(target,source);	\

#endif
#ifndef CopyDiskIOEntity
#define CopyDiskIOEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->PartName=(source)->PartName;	\
			(target)->ReadMerges=(source)->ReadMerges;	\
			(target)->WriteMerges=(source)->WriteMerges;	\
			(target)->ReadIOs=(source)->ReadIOs;	\
			(target)->WriteIOs=(source)->WriteIOs;	\
			(target)->ReadKBs=(source)->ReadKBs;	\
			(target)->WriteKBs=(source)->WriteKBs;	\
			(target)->SizeVal=(source)->SizeVal;	\
			(target)->QueueVal=(source)->QueueVal;	\
			(target)->Svc_t=(source)->Svc_t;	\
			(target)->Busy=(source)->Busy;	\

#endif
#ifndef CopyReqQryDiskIOEntity
#define CopyReqQryDiskIOEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryDiskIOEntity
#define CopyRspQryDiskIOEntity(target,source)	\
			CopyDiskIOEntity(target,source);	\

#endif
#ifndef CopyRtnDiskIOEntity
#define CopyRtnDiskIOEntity(target,source)	\
			CopyDiskIOEntity(target,source);	\

#endif
#ifndef CopySysMdbDiskIOEntity
#define CopySysMdbDiskIOEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			CopyDiskIOEntity(target,source);	\

#endif
#ifndef CopyStatInfoEntity
#define CopyStatInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ProcRun=(source)->ProcRun;	\
			(target)->ProcBlk=(source)->ProcBlk;	\
			(target)->SwapIn=(source)->SwapIn;	\
			(target)->SwapOut=(source)->SwapOut;	\
			(target)->BlockIn=(source)->BlockIn;	\
			(target)->BlockOut=(source)->BlockOut;	\
			(target)->Inter=(source)->Inter;	\
			(target)->Context=(source)->Context;	\
			(target)->CPUUser=(source)->CPUUser;	\
			(target)->CPUSys=(source)->CPUSys;	\
			(target)->CPUIdle=(source)->CPUIdle;	\
			(target)->CPUIOWait=(source)->CPUIOWait;	\
			(target)->CPUSteal=(source)->CPUSteal;	\

#endif
#ifndef CopyReqQryStatInfoEntity
#define CopyReqQryStatInfoEntity(target,source)	\
			(target)->HostName=(source)->HostName;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\
			(target)->KeepAlive=(source)->KeepAlive;	\

#endif
#ifndef CopyRspQryStatInfoEntity
#define CopyRspQryStatInfoEntity(target,source)	\
			CopyStatInfoEntity(target,source);	\

#endif
#ifndef CopyRtnStatInfoEntity
#define CopyRtnStatInfoEntity(target,source)	\
			CopyStatInfoEntity(target,source);	\

#endif
#ifndef CopySysMdbStatInfoEntity
#define CopySysMdbStatInfoEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			CopyStatInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryClientInfoEntity
#define CopyReqQryClientInfoEntity(target,source)	\
			(target)->ClientID=(source)->ClientID;	\
			(target)->ClientName=(source)->ClientName;	\

#endif
#ifndef CopyRspQryClientInfoEntity
#define CopyRspQryClientInfoEntity(target,source)	\
			CopySysClientInitEntity(target,source);	\

#endif
#ifndef CopyRtnClientInfoEntity
#define CopyRtnClientInfoEntity(target,source)	\
			CopySysClientInitEntity(target,source);	\

#endif
#ifndef CopySysPerformanceTopEntity
#define CopySysPerformanceTopEntity(target,source)	\
			(target)->OperationType=(source)->OperationType;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->NetArea=(source)->NetArea;	\
			(target)->NetSubArea=(source)->NetSubArea;	\
			(target)->KeyWord=(source)->KeyWord;	\
			(target)->SortValue=(source)->SortValue;	\
			(target)->SortType=(source)->SortType;	\
			(target)->DuringTimeType=(source)->DuringTimeType;	\
			(target)->DuringTimeValue=(source)->DuringTimeValue;	\
			(target)->TopN=(source)->TopN;	\
			(target)->TopResult=(source)->TopResult;	\

#endif
#ifndef CopyReqQryPerformanceTopEntity
#define CopyReqQryPerformanceTopEntity(target,source)	\
			CopySysPerformanceTopEntity(target,source);	\

#endif
#ifndef CopyRspQryPerformanceTopEntity
#define CopyRspQryPerformanceTopEntity(target,source)	\
			CopySysPerformanceTopEntity(target,source);	\

#endif
#ifndef CopyRtnPerformanceTopEntity
#define CopyRtnPerformanceTopEntity(target,source)	\
			CopySysPerformanceTopEntity(target,source);	\

#endif
#ifndef CopySysEventDescripEntity
#define CopySysEventDescripEntity(target,source)	\
			(target)->EventDesID=(source)->EventDesID;	\
			(target)->UserName=(source)->UserName;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->EventDes=(source)->EventDes;	\

#endif
#ifndef CopyReqQryEventDescriptionEntity
#define CopyReqQryEventDescriptionEntity(target,source)	\
			CopySysEventDescripEntity(target,source);	\

#endif
#ifndef CopyRspQryEventDescriptionEntity
#define CopyRspQryEventDescriptionEntity(target,source)	\
			CopySysEventDescripEntity(target,source);	\

#endif
#ifndef CopyRtnEventDescriptionEntity
#define CopyRtnEventDescriptionEntity(target,source)	\
			CopySysEventDescripEntity(target,source);	\

#endif
#ifndef CopySysFrontUniqueIDEntity
#define CopySysFrontUniqueIDEntity(target,source)	\
			(target)->FrontID=(source)->FrontID;	\
			(target)->FrontName=(source)->FrontName;	\

#endif
#ifndef CopyReqQryFrontUniqueIDEntity
#define CopyReqQryFrontUniqueIDEntity(target,source)	\
			CopySysFrontUniqueIDEntity(target,source);	\

#endif
#ifndef CopyRspQryFrontUniqueIDEntity
#define CopyRspQryFrontUniqueIDEntity(target,source)	\
			CopySysFrontUniqueIDEntity(target,source);	\

#endif
#ifndef CopyRtnFrontUniqueIDEntity
#define CopyRtnFrontUniqueIDEntity(target,source)	\
			CopySysFrontUniqueIDEntity(target,source);	\

#endif
#ifndef CopySysInstrumentStatusEntity
#define CopySysInstrumentStatusEntity(target,source)	\
			CopyInstrumentStatusEntity(target,source);	\

#endif
#ifndef CopyReqQryInstrumentStatusEntity
#define CopyReqQryInstrumentStatusEntity(target,source)	\
			CopySysInstrumentStatusEntity(target,source);	\

#endif
#ifndef CopyRspQryInstrumentStatusEntity
#define CopyRspQryInstrumentStatusEntity(target,source)	\
			CopySysInstrumentStatusEntity(target,source);	\

#endif
#ifndef CopyRtnInstrumentStatusEntity
#define CopyRtnInstrumentStatusEntity(target,source)	\
			CopySysInstrumentStatusEntity(target,source);	\

#endif
#ifndef CopySysCurrTradingSegmentAttrEntity
#define CopySysCurrTradingSegmentAttrEntity(target,source)	\
			CopyCurrTradingSegmentAttrEntity(target,source);	\

#endif
#ifndef CopyReqQryCurrTradingSegmentAttrEntity
#define CopyReqQryCurrTradingSegmentAttrEntity(target,source)	\
			CopySysCurrTradingSegmentAttrEntity(target,source);	\

#endif
#ifndef CopyRspQryCurrTradingSegmentAttrEntity
#define CopyRspQryCurrTradingSegmentAttrEntity(target,source)	\
			CopySysCurrTradingSegmentAttrEntity(target,source);	\

#endif
#ifndef CopyRtnCurrTradingSegmentAttrEntity
#define CopyRtnCurrTradingSegmentAttrEntity(target,source)	\
			CopySysCurrTradingSegmentAttrEntity(target,source);	\

#endif
#ifndef CopySysNetDelPartyLinkInfoEntity
#define CopySysNetDelPartyLinkInfoEntity(target,source)	\
			CopySysNetPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryNetDelPartyLinkInfoEntity
#define CopyReqQryNetDelPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDelPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetDelPartyLinkInfoEntity
#define CopyRspQryNetDelPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDelPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetDelPartyLinkInfoEntity
#define CopyRtnNetDelPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDelPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopySysNetPartyLinkAddrChangeEntity
#define CopySysNetPartyLinkAddrChangeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->RelationID=(source)->RelationID;	\
			(target)->OLDADDRESS=(source)->OLDADDRESS;	\
			(target)->NEWADDRESS=(source)->NEWADDRESS;	\
			(target)->OPERATOR=(source)->OPERATOR;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\

#endif
#ifndef CopyReqQryNetPartyLinkAddrChangeEntity
#define CopyReqQryNetPartyLinkAddrChangeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkAddrChangeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPartyLinkAddrChangeEntity
#define CopyRspQryNetPartyLinkAddrChangeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkAddrChangeEntity(target,source);	\

#endif
#ifndef CopyRtnNetPartyLinkAddrChangeEntity
#define CopyRtnNetPartyLinkAddrChangeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkAddrChangeEntity(target,source);	\

#endif
#ifndef CopyOperateTypeRefEntity
#define CopyOperateTypeRefEntity(target,source)	\
			(target)->OperationType=(source)->OperationType;	\

#endif
#ifndef CopySearchKeyInfoEntity
#define CopySearchKeyInfoEntity(target,source)	\
			(target)->KeyCompare=(source)->KeyCompare;	\
			(target)->KeyName=(source)->KeyName;	\
			(target)->KeyValue=(source)->KeyValue;	\

#endif
#ifndef CopySysGeneralOperateEntity
#define CopySysGeneralOperateEntity(target,source)	\
			(target)->GeneralOperateType=(source)->GeneralOperateType;	\
			(target)->GeneralOperateTable=(source)->GeneralOperateTable;	\
			(target)->GeneralOperateOption=(source)->GeneralOperateOption;	\
			(target)->GeneralOperateSet=(source)->GeneralOperateSet;	\

#endif
#ifndef CopyReqQryGeneralOperateEntity
#define CopyReqQryGeneralOperateEntity(target,source)	\
			CopySysGeneralOperateEntity(target,source);	\

#endif
#ifndef CopyRspQryGeneralOperateEntity
#define CopyRspQryGeneralOperateEntity(target,source)	\
			CopySysGeneralOperateEntity(target,source);	\

#endif
#ifndef CopyRtnGeneralOperateEntity
#define CopyRtnGeneralOperateEntity(target,source)	\
			CopySysGeneralOperateEntity(target,source);	\

#endif
#ifndef CopySysNetDeviceEntity
#define CopySysNetDeviceEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonitorType_ID=(source)->MonitorType_ID;	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->CATEGORY_ID=(source)->CATEGORY_ID;	\
			(target)->FuctionArea=(source)->FuctionArea;	\
			(target)->IPADDR=(source)->IPADDR;	\
			(target)->IPDECODE=(source)->IPDECODE;	\
			(target)->NAME=(source)->NAME;	\
			(target)->PORTNUMBER=(source)->PORTNUMBER;	\
			(target)->CONFIGFILE=(source)->CONFIGFILE;	\
			(target)->RCOMMUNITY=(source)->RCOMMUNITY;	\
			(target)->SNMPVERSION=(source)->SNMPVERSION;	\
			(target)->RAMSIZE=(source)->RAMSIZE;	\
			(target)->FLASHSIZE=(source)->FLASHSIZE;	\
			(target)->NVRAMSIZE=(source)->NVRAMSIZE;	\
			(target)->CABINET_ID=(source)->CABINET_ID;	\
			(target)->ROOM_ID=(source)->ROOM_ID;	\
			(target)->IOSVERSION_ID=(source)->IOSVERSION_ID;	\
			(target)->DESCRIPTION=(source)->DESCRIPTION;	\
			(target)->USERNAME=(source)->USERNAME;	\
			(target)->PASSWD=(source)->PASSWD;	\
			(target)->ENPASSWD=(source)->ENPASSWD;	\
			(target)->MANUFACTORY_ID=(source)->MANUFACTORY_ID;	\
			(target)->CFGSAVETYPE=(source)->CFGSAVETYPE;	\
			(target)->DEVICETYPE=(source)->DEVICETYPE;	\
			(target)->SENDSMS=(source)->SENDSMS;	\
			(target)->ISSNMP=(source)->ISSNMP;	\
			(target)->SLOTNUM=(source)->SLOTNUM;	\
			(target)->ISPING=(source)->ISPING;	\
			(target)->IFNUM=(source)->IFNUM;	\
			(target)->APPLICATION_ID=(source)->APPLICATION_ID;	\

#endif
#ifndef CopyReqQryNetDeviceDetectEntity
#define CopyReqQryNetDeviceDetectEntity(target,source)	\
			(target)->SysNetAreaID=(source)->SysNetAreaID;	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->IP=(source)->IP;	\
			(target)->Mask=(source)->Mask;	\

#endif
#ifndef CopyRspQryNetDeviceDetectEntity
#define CopyRspQryNetDeviceDetectEntity(target,source)	\
			CopyReqQryNetDeviceDetectEntity(target,source);	\

#endif
#ifndef CopyReqQryNetDeviceRequestEntity
#define CopyReqQryNetDeviceRequestEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->FuctionArea=(source)->FuctionArea;	\
			(target)->IPDECODE=(source)->IPDECODE;	\

#endif
#ifndef CopyRspQryNetDeviceEntity
#define CopyRspQryNetDeviceEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceEntity(target,source);	\

#endif
#ifndef CopyRtnNetDeviceEntity
#define CopyRtnNetDeviceEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceEntity(target,source);	\

#endif
#ifndef CopySysNetDeviceLinkedEntity
#define CopySysNetDeviceLinkedEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->NetDeviceID=(source)->NetDeviceID;	\
			(target)->NetPortID=(source)->NetPortID;	\
			(target)->NetObjectID=(source)->NetObjectID;	\
			(target)->NetPortType=(source)->NetPortType;	\
			(target)->LinkNetDeviceID=(source)->LinkNetDeviceID;	\
			(target)->LinkNetPortID=(source)->LinkNetPortID;	\
			(target)->LinkNetObjectID=(source)->LinkNetObjectID;	\
			(target)->LinkNetPortType=(source)->LinkNetPortType;	\
			(target)->LinkSource=(source)->LinkSource;	\

#endif
#ifndef CopyReqQryNetDeviceLinkedEntity
#define CopyReqQryNetDeviceLinkedEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->FuctionArea=(source)->FuctionArea;	\
			(target)->IPDECODE=(source)->IPDECODE;	\
			(target)->ObjectID=(source)->ObjectID;	\

#endif
#ifndef CopyRspQryNetDeviceLinkedEntity
#define CopyRspQryNetDeviceLinkedEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceLinkedEntity(target,source);	\

#endif
#ifndef CopyRtnNetDeviceLinkedEntity
#define CopyRtnNetDeviceLinkedEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceLinkedEntity(target,source);	\

#endif
#ifndef CopyReqQryObjectAttrEntity
#define CopyReqQryObjectAttrEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->StartDate=(source)->StartDate;	\
			(target)->StartTime=(source)->StartTime;	\
			(target)->EndDate=(source)->EndDate;	\
			(target)->EndTime=(source)->EndTime;	\

#endif
#ifndef CopySysObjectAttrEntity
#define CopySysObjectAttrEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ValueType=(source)->ValueType;	\
			(target)->AttrValue=(source)->AttrValue;	\

#endif
#ifndef CopySysMdbObjectAttrEntity
#define CopySysMdbObjectAttrEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->ValueType=(source)->ValueType;	\
			(target)->AttrValue=(source)->AttrValue;	\

#endif
#ifndef CopyRspQryObjectAttrEntity
#define CopyRspQryObjectAttrEntity(target,source)	\
			CopySysObjectAttrEntity(target,source);	\

#endif
#ifndef CopyRtnObjectAttrEntity
#define CopyRtnObjectAttrEntity(target,source)	\
			CopySysObjectAttrEntity(target,source);	\

#endif
#ifndef CopyReqQryRealTimeNetObjectAttrEntity
#define CopyReqQryRealTimeNetObjectAttrEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopySysMemberLinkCostEntity
#define CopySysMemberLinkCostEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->DDN_NO=(source)->DDN_NO;	\
			(target)->ServiceProvider=(source)->ServiceProvider;	\
			(target)->Pay_Date=(source)->Pay_Date;	\
			(target)->B_Pay_Date=(source)->B_Pay_Date;	\
			(target)->D_Pay_Date=(source)->D_Pay_Date;	\
			(target)->Charge=(source)->Charge;	\
			(target)->Fee_Type=(source)->Fee_Type;	\
			(target)->Pro=(source)->Pro;	\

#endif
#ifndef CopyReqQryMemberLinkCostEntity
#define CopyReqQryMemberLinkCostEntity(target,source)	\
			CopySysMemberLinkCostEntity(target,source);	\

#endif
#ifndef CopyRspQryMemberLinkCostEntity
#define CopyRspQryMemberLinkCostEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysMemberLinkCostEntity(target,source);	\

#endif
#ifndef CopyRtnMemberLinkCostEntity
#define CopyRtnMemberLinkCostEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysMemberLinkCostEntity(target,source);	\

#endif
#ifndef CopySysNetAreaEntity
#define CopySysNetAreaEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetAreaEntity
#define CopyReqQryNetAreaEntity(target,source)	\
			(target)->ID=(source)->ID;	\

#endif
#ifndef CopyRspQryNetAreaEntity
#define CopyRspQryNetAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetAreaEntity(target,source);	\

#endif
#ifndef CopyRtnNetAreaEntity
#define CopyRtnNetAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetAreaEntity(target,source);	\

#endif
#ifndef CopySysNetSubAreaEntity
#define CopySysNetSubAreaEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetAreaID=(source)->SysNetAreaID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetSubAreaEntity
#define CopyReqQryNetSubAreaEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetAreaID=(source)->SysNetAreaID;	\

#endif
#ifndef CopyRspQryNetSubAreaEntity
#define CopyRspQryNetSubAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubAreaEntity(target,source);	\

#endif
#ifndef CopyRtnNetSubAreaEntity
#define CopyRtnNetSubAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubAreaEntity(target,source);	\

#endif
#ifndef CopySysNetSubAreaIPEntity
#define CopySysNetSubAreaIPEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->IP=(source)->IP;	\
			(target)->Mask=(source)->Mask;	\

#endif
#ifndef CopyReqQryNetSubAreaIPEntity
#define CopyReqQryNetSubAreaIPEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetAreaID=(source)->SysNetAreaID;	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\

#endif
#ifndef CopyRspQryNetSubAreaIPEntity
#define CopyRspQryNetSubAreaIPEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubAreaIPEntity(target,source);	\

#endif
#ifndef CopyRtnNetSubAreaIPEntity
#define CopyRtnNetSubAreaIPEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubAreaIPEntity(target,source);	\

#endif
#ifndef CopySysNetFuncAreaEntity
#define CopySysNetFuncAreaEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetFuncAreaEntity
#define CopyReqQryNetFuncAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetFuncAreaEntity(target,source);	\

#endif
#ifndef CopyRspQryNetFuncAreaEntity
#define CopyRspQryNetFuncAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetFuncAreaEntity(target,source);	\

#endif
#ifndef CopyRtnNetFuncAreaEntity
#define CopyRtnNetFuncAreaEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetFuncAreaEntity(target,source);	\

#endif
#ifndef CopySysNetBuildingEntity
#define CopySysNetBuildingEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetBuildingEntity
#define CopyReqQryNetBuildingEntity(target,source)	\
			(target)->ID=(source)->ID;	\

#endif
#ifndef CopyRspQryNetBuildingEntity
#define CopyRspQryNetBuildingEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBuildingEntity(target,source);	\

#endif
#ifndef CopyRtnNetBuildingEntity
#define CopyRtnNetBuildingEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBuildingEntity(target,source);	\

#endif
#ifndef CopySysNetRoomEntity
#define CopySysNetRoomEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetBuildingID=(source)->SysNetBuildingID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetRoomEntity
#define CopyReqQryNetRoomEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetBuildingID=(source)->SysNetBuildingID;	\

#endif
#ifndef CopyRspQryNetRoomEntity
#define CopyRspQryNetRoomEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetRoomEntity(target,source);	\

#endif
#ifndef CopyRtnNetRoomEntity
#define CopyRtnNetRoomEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetRoomEntity(target,source);	\

#endif
#ifndef CopySysNetCabinetsEntity
#define CopySysNetCabinetsEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetRoomID=(source)->SysNetRoomID;	\
			(target)->SysNetBuildingID=(source)->SysNetBuildingID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->CabinetsType=(source)->CabinetsType;	\

#endif
#ifndef CopyReqQryNetCabinetsEntity
#define CopyReqQryNetCabinetsEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SysNetRoomID=(source)->SysNetRoomID;	\
			(target)->SysNetBuildingID=(source)->SysNetBuildingID;	\

#endif
#ifndef CopyRspQryNetCabinetsEntity
#define CopyRspQryNetCabinetsEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCabinetsEntity(target,source);	\

#endif
#ifndef CopyRtnNetCabinetsEntity
#define CopyRtnNetCabinetsEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCabinetsEntity(target,source);	\

#endif
#ifndef CopySysNetDeviceTypeEntity
#define CopySysNetDeviceTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->Manufactory=(source)->Manufactory;	\
			(target)->DeviceType=(source)->DeviceType;	\

#endif
#ifndef CopyReqQryNetDeviceTypeEntity
#define CopyReqQryNetDeviceTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetDeviceTypeEntity
#define CopyRspQryNetDeviceTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetDeviceTypeEntity
#define CopyRtnNetDeviceTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceTypeEntity(target,source);	\

#endif
#ifndef CopySysNetOIDEntity
#define CopySysNetOIDEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->Manufactory=(source)->Manufactory;	\
			(target)->DeviceType=(source)->DeviceType;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->OID=(source)->OID;	\
			(target)->Unit=(source)->Unit;	\
			(target)->isTheTable=(source)->isTheTable;	\

#endif
#ifndef CopyReqQryNetOIDEntity
#define CopyReqQryNetOIDEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetOIDEntity(target,source);	\

#endif
#ifndef CopyRspQryNetOIDEntity
#define CopyRspQryNetOIDEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetOIDEntity(target,source);	\

#endif
#ifndef CopyRtnNetOIDEntity
#define CopyRtnNetOIDEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetOIDEntity(target,source);	\

#endif
#ifndef CopySysNetTimePolicyEntity
#define CopySysNetTimePolicyEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->PolicyType=(source)->PolicyType;	\
			(target)->PolicyString=(source)->PolicyString;	\
			(target)->TradingDay=(source)->TradingDay;	\
			(target)->Description=(source)->Description;	\
			(target)->Operation=(source)->Operation;	\

#endif
#ifndef CopyReqQryNetTimePolicyEntity
#define CopyReqQryNetTimePolicyEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetTimePolicyEntity(target,source);	\

#endif
#ifndef CopyRspQryNetTimePolicyEntity
#define CopyRspQryNetTimePolicyEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetTimePolicyEntity(target,source);	\

#endif
#ifndef CopyRtnNetTimePolicyEntity
#define CopyRtnNetTimePolicyEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetTimePolicyEntity(target,source);	\

#endif
#ifndef CopySysNetGatherTaskEntity
#define CopySysNetGatherTaskEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->PolicyTypeID=(source)->PolicyTypeID;	\
			(target)->DataType=(source)->DataType;	\
			(target)->TypeFlag=(source)->TypeFlag;	\

#endif
#ifndef CopyReqQryNetGatherTaskEntity
#define CopyReqQryNetGatherTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetGatherTaskEntity(target,source);	\

#endif
#ifndef CopyRspQryNetGatherTaskEntity
#define CopyRspQryNetGatherTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetGatherTaskEntity(target,source);	\

#endif
#ifndef CopyRtnNetGatherTaskEntity
#define CopyRtnNetGatherTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetGatherTaskEntity(target,source);	\

#endif
#ifndef CopySysNetDeviceChgEntity
#define CopySysNetDeviceChgEntity(target,source)	\
			(target)->DeviceID=(source)->DeviceID;	\
			(target)->SysNetSubAreaID=(source)->SysNetSubAreaID;	\
			(target)->OldObjectID=(source)->OldObjectID;	\
			(target)->NewObjectID=(source)->NewObjectID;	\

#endif
#ifndef CopyReqQryNetDeviceChgEntity
#define CopyReqQryNetDeviceChgEntity(target,source)	\
			CopySysNetDeviceChgEntity(target,source);	\

#endif
#ifndef CopyRspQryNetDeviceChgEntity
#define CopyRspQryNetDeviceChgEntity(target,source)	\
			CopySysNetDeviceChgEntity(target,source);	\

#endif
#ifndef CopyRtnNetDeviceChgEntity
#define CopyRtnNetDeviceChgEntity(target,source)	\
			CopySysNetDeviceChgEntity(target,source);	\

#endif
#ifndef CopySysNetDeviceCategoryEntity
#define CopySysNetDeviceCategoryEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetDeviceCategoryEntity
#define CopyReqQryNetDeviceCategoryEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceCategoryEntity(target,source);	\

#endif
#ifndef CopyRspQryNetDeviceCategoryEntity
#define CopyRspQryNetDeviceCategoryEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceCategoryEntity(target,source);	\

#endif
#ifndef CopyRtnNetDeviceCategoryEntity
#define CopyRtnNetDeviceCategoryEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDeviceCategoryEntity(target,source);	\

#endif
#ifndef CopySysNetManufactoryEntity
#define CopySysNetManufactoryEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetManufactoryEntity
#define CopyReqQryNetManufactoryEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetManufactoryEntity(target,source);	\

#endif
#ifndef CopyRspQryNetManufactoryEntity
#define CopyRspQryNetManufactoryEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetManufactoryEntity(target,source);	\

#endif
#ifndef CopyRtnNetManufactoryEntity
#define CopyRtnNetManufactoryEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetManufactoryEntity(target,source);	\

#endif
#ifndef CopySysNetCommunityEntity
#define CopySysNetCommunityEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->IPADDR=(source)->IPADDR;	\
			(target)->COMMUNITY=(source)->COMMUNITY;	\

#endif
#ifndef CopyReqQryNetCommunityEntity
#define CopyReqQryNetCommunityEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCommunityEntity(target,source);	\

#endif
#ifndef CopyRspQryNetCommunityEntity
#define CopyRspQryNetCommunityEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCommunityEntity(target,source);	\

#endif
#ifndef CopyRtnNetCommunityEntity
#define CopyRtnNetCommunityEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCommunityEntity(target,source);	\

#endif
#ifndef CopySysNetPortTypeEntity
#define CopySysNetPortTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->Description=(source)->Description;	\

#endif
#ifndef CopyReqQryNetPortTypeEntity
#define CopyReqQryNetPortTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPortTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPortTypeEntity
#define CopyRspQryNetPortTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPortTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetPortTypeEntity
#define CopyRtnNetPortTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPortTypeEntity(target,source);	\

#endif
#ifndef CopySysNetPartAccessSpotEntity
#define CopySysNetPartAccessSpotEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetPartAccessSpotEntity
#define CopyReqQryNetPartAccessSpotEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartAccessSpotEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPartAccessSpotEntity
#define CopyRspQryNetPartAccessSpotEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartAccessSpotEntity(target,source);	\

#endif
#ifndef CopyRtnNetPartAccessSpotEntity
#define CopyRtnNetPartAccessSpotEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartAccessSpotEntity(target,source);	\

#endif
#ifndef CopySysNetInterfaceEntity
#define CopySysNetInterfaceEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonitorType_ID=(source)->MonitorType_ID;	\
			(target)->IfType=(source)->IfType;	\
			(target)->EName=(source)->EName;	\
			(target)->IpAddress=(source)->IpAddress;	\
			(target)->IpMask=(source)->IpMask;	\
			(target)->IfStatus=(source)->IfStatus;	\
			(target)->MAC=(source)->MAC;	\
			(target)->DeviceID=(source)->DeviceID;	\
			(target)->DeviceObjectID=(source)->DeviceObjectID;	\
			(target)->DeviceIndex=(source)->DeviceIndex;	\
			(target)->isPolling=(source)->isPolling;	\
			(target)->Description=(source)->Description;	\

#endif
#ifndef CopyReqQryNetInterfaceEntity
#define CopyReqQryNetInterfaceEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetInterfaceEntity(target,source);	\

#endif
#ifndef CopyRspQryNetInterfaceEntity
#define CopyRspQryNetInterfaceEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetInterfaceEntity(target,source);	\

#endif
#ifndef CopyRtnNetInterfaceEntity
#define CopyRtnNetInterfaceEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetInterfaceEntity(target,source);	\

#endif
#ifndef CopySysNetGeneralOIDEntity
#define CopySysNetGeneralOIDEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->OID=(source)->OID;	\
			(target)->Unit=(source)->Unit;	\
			(target)->isTheTable=(source)->isTheTable;	\

#endif
#ifndef CopyReqQryNetGeneralOIDEntity
#define CopyReqQryNetGeneralOIDEntity(target,source)	\
			(target)->ID=(source)->ID;	\

#endif
#ifndef CopyRspQryNetGeneralOIDEntity
#define CopyRspQryNetGeneralOIDEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetGeneralOIDEntity(target,source);	\

#endif
#ifndef CopyRtnNetGeneralOIDEntity
#define CopyRtnNetGeneralOIDEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetGeneralOIDEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorTypeEntity
#define CopySysNetMonitorTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetMonitorTypeEntity
#define CopyReqQryNetMonitorTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorTypeEntity
#define CopyRspQryNetMonitorTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorTypeEntity
#define CopyRtnNetMonitorTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTypeEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorAttrScopeEntity
#define CopySysNetMonitorAttrScopeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->Comments=(source)->Comments;	\

#endif
#ifndef CopyReqQryNetMonitorAttrScopeEntity
#define CopyReqQryNetMonitorAttrScopeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorAttrScopeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorAttrScopeEntity
#define CopyRspQryNetMonitorAttrScopeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorAttrScopeEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorAttrScopeEntity
#define CopyRtnNetMonitorAttrScopeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorAttrScopeEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorAttrTypeEntity
#define CopySysNetMonitorAttrTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->MANUFACTORY_ID=(source)->MANUFACTORY_ID;	\
			(target)->MonitorType_ID=(source)->MonitorType_ID;	\
			(target)->AttrType_ID=(source)->AttrType_ID;	\
			(target)->MANUFACTORY=(source)->MANUFACTORY;	\
			(target)->MonitorType=(source)->MonitorType;	\
			(target)->AttrType=(source)->AttrType;	\

#endif
#ifndef CopyReqQryNetMonitorAttrTypeEntity
#define CopyReqQryNetMonitorAttrTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorAttrTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorAttrTypeEntity
#define CopyRspQryNetMonitorAttrTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorAttrTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorAttrTypeEntity
#define CopyRtnNetMonitorAttrTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorAttrTypeEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorObjectAttrEntity
#define CopySysNetMonitorObjectAttrEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->AttrType=(source)->AttrType;	\
			(target)->PolicyTypeID=(source)->PolicyTypeID;	\

#endif
#ifndef CopyReqQryNetMonitorObjectAttrEntity
#define CopyReqQryNetMonitorObjectAttrEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorObjectAttrEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorObjectAttrEntity
#define CopyRspQryNetMonitorObjectAttrEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorObjectAttrEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorObjectAttrEntity
#define CopyRtnNetMonitorObjectAttrEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorObjectAttrEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorCommandTypeEntity
#define CopySysNetMonitorCommandTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->Manufactory_ID=(source)->Manufactory_ID;	\
			(target)->MonitorType_ID=(source)->MonitorType_ID;	\
			(target)->DeviceModle_ID=(source)->DeviceModle_ID;	\
			(target)->ActionGroup_ID=(source)->ActionGroup_ID;	\
			(target)->Manufactory=(source)->Manufactory;	\
			(target)->MonitorType=(source)->MonitorType;	\
			(target)->DeviceModle=(source)->DeviceModle;	\
			(target)->ActionGroup=(source)->ActionGroup;	\
			(target)->Command=(source)->Command;	\

#endif
#ifndef CopyReqQryNetMonitorCommandTypeEntity
#define CopyReqQryNetMonitorCommandTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorCommandTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorCommandTypeEntity
#define CopyRspQryNetMonitorCommandTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorCommandTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorCommandTypeEntity
#define CopyRtnNetMonitorCommandTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorCommandTypeEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorActionGroupEntity
#define CopySysNetMonitorActionGroupEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->ActionType=(source)->ActionType;	\
			(target)->Comments=(source)->Comments;	\

#endif
#ifndef CopyReqQryNetMonitorActionGroupEntity
#define CopyReqQryNetMonitorActionGroupEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorActionGroupEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorActionGroupEntity
#define CopyRspQryNetMonitorActionGroupEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorActionGroupEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorActionGroupEntity
#define CopyRtnNetMonitorActionGroupEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorActionGroupEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorDeviceGroupEntity
#define CopySysNetMonitorDeviceGroupEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->Condition=(source)->Condition;	\
			(target)->Comments=(source)->Comments;	\

#endif
#ifndef CopyReqQryNetMonitorDeviceGroupEntity
#define CopyReqQryNetMonitorDeviceGroupEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorDeviceGroupEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorDeviceGroupEntity
#define CopyRspQryNetMonitorDeviceGroupEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorDeviceGroupEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorDeviceGroupEntity
#define CopyRtnNetMonitorDeviceGroupEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorDeviceGroupEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorTaskInfoEntity
#define CopySysNetMonitorTaskInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->DeviceGroup_ID=(source)->DeviceGroup_ID;	\
			(target)->ManagerGroup_ID=(source)->ManagerGroup_ID;	\
			(target)->TimePolicy_ID=(source)->TimePolicy_ID;	\
			(target)->TaskPriority_ID=(source)->TaskPriority_ID;	\
			(target)->OutputPolicy_ID=(source)->OutputPolicy_ID;	\
			(target)->ActionGroup_ID=(source)->ActionGroup_ID;	\
			(target)->EventExprStr=(source)->EventExprStr;	\
			(target)->DeviceGroup=(source)->DeviceGroup;	\
			(target)->ManagerGroup=(source)->ManagerGroup;	\
			(target)->TimePolicy=(source)->TimePolicy;	\
			(target)->TaskPriority=(source)->TaskPriority;	\
			(target)->OutputPolicy=(source)->OutputPolicy;	\
			(target)->ActionGroup=(source)->ActionGroup;	\
			(target)->ValidFlag=(source)->ValidFlag;	\
			(target)->TaskStatus=(source)->TaskStatus;	\
			(target)->Comments=(source)->Comments;	\

#endif
#ifndef CopyReqQryNetMonitorTaskInfoEntity
#define CopyReqQryNetMonitorTaskInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorTaskInfoEntity
#define CopyRspQryNetMonitorTaskInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorTaskInfoEntity
#define CopyRtnNetMonitorTaskInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskInfoEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorTaskResultEntity
#define CopySysNetMonitorTaskResultEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->Task_ID=(source)->Task_ID;	\
			(target)->OperateTime=(source)->OperateTime;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->InstructChain=(source)->InstructChain;	\
			(target)->ResultChain=(source)->ResultChain;	\
			(target)->Flag=(source)->Flag;	\

#endif
#ifndef CopyReqQryNetMonitorTaskResultEntity
#define CopyReqQryNetMonitorTaskResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskResultEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorTaskResultEntity
#define CopyRspQryNetMonitorTaskResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskResultEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorTaskResultEntity
#define CopyRtnNetMonitorTaskResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskResultEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorTaskStatusResultEntity
#define CopySysNetMonitorTaskStatusResultEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->Task_ID=(source)->Task_ID;	\
			(target)->OperateTime=(source)->OperateTime;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->Flag=(source)->Flag;	\

#endif
#ifndef CopyReqQryNetMonitorTaskStatusResultEntity
#define CopyReqQryNetMonitorTaskStatusResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskStatusResultEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorTaskStatusResultEntity
#define CopyRspQryNetMonitorTaskStatusResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskStatusResultEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorTaskStatusResultEntity
#define CopyRtnNetMonitorTaskStatusResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskStatusResultEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorTaskObjectSetEntity
#define CopySysNetMonitorTaskObjectSetEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->DeviceGroup_ID=(source)->DeviceGroup_ID;	\
			(target)->Device_ID=(source)->Device_ID;	\
			(target)->DataCenter=(source)->DataCenter;	\

#endif
#ifndef CopyReqQryNetMonitorTaskObjectSetEntity
#define CopyReqQryNetMonitorTaskObjectSetEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskObjectSetEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorTaskObjectSetEntity
#define CopyRspQryNetMonitorTaskObjectSetEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskObjectSetEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorTaskObjectSetEntity
#define CopyRtnNetMonitorTaskObjectSetEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskObjectSetEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorDeviceTaskEntity
#define CopySysNetMonitorDeviceTaskEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->IPAddress=(source)->IPAddress;	\
			(target)->Manufactory_ID=(source)->Manufactory_ID;	\
			(target)->InstructChain=(source)->InstructChain;	\
			(target)->InstructAlias=(source)->InstructAlias;	\
			(target)->InstructArgs=(source)->InstructArgs;	\
			(target)->DefParamChain=(source)->DefParamChain;	\
			(target)->Flag=(source)->Flag;	\

#endif
#ifndef CopyReqQryNetMonitorDeviceTaskEntity
#define CopyReqQryNetMonitorDeviceTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorDeviceTaskEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorDeviceTaskEntity
#define CopyRspQryNetMonitorDeviceTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorDeviceTaskEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorDeviceTaskEntity
#define CopyRtnNetMonitorDeviceTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorDeviceTaskEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorDeviceTask2Entity
#define CopySysNetMonitorDeviceTask2Entity(target,source)	\
			CopySysNetMonitorDeviceTaskEntity(target,source);	\
			(target)->SecondID=(source)->SecondID;	\

#endif
#ifndef CopySysNetMonitorTaskInstAttrsEntity
#define CopySysNetMonitorTaskInstAttrsEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->Manufactory_ID=(source)->Manufactory_ID;	\
			(target)->InstructAlias=(source)->InstructAlias;	\
			(target)->DEVICETYPE=(source)->DEVICETYPE;	\
			(target)->AttrsChain=(source)->AttrsChain;	\
			(target)->DefRegularChain=(source)->DefRegularChain;	\
			(target)->DefParamChain=(source)->DefParamChain;	\

#endif
#ifndef CopyReqQryNetMonitorTaskInstAttrsEntity
#define CopyReqQryNetMonitorTaskInstAttrsEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskInstAttrsEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorTaskInstAttrsEntity
#define CopyRspQryNetMonitorTaskInstAttrsEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskInstAttrsEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorTaskInstAttrsEntity
#define CopyRtnNetMonitorTaskInstAttrsEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorTaskInstAttrsEntity(target,source);	\

#endif
#ifndef CopySysNetPartyLinkInfoEntity
#define CopySysNetPartyLinkInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->MEMBER_NO=(source)->MEMBER_NO;	\
			(target)->MEMBER_NAME=(source)->MEMBER_NAME;	\
			(target)->REMOTE_ADDR=(source)->REMOTE_ADDR;	\
			(target)->LOCAL_ADDR=(source)->LOCAL_ADDR;	\
			(target)->ADDRESS=(source)->ADDRESS;	\
			(target)->LINE_STATUS=(source)->LINE_STATUS;	\
			(target)->CONTACT=(source)->CONTACT;	\
			(target)->TELEPHONE=(source)->TELEPHONE;	\
			(target)->MOBILEPHONE=(source)->MOBILEPHONE;	\
			(target)->EMAIL=(source)->EMAIL;	\
			(target)->FAX=(source)->FAX;	\
			(target)->PROVINCE=(source)->PROVINCE;	\
			(target)->DDN_NO=(source)->DDN_NO;	\
			(target)->IN_MODE=(source)->IN_MODE;	\
			(target)->IP_WAN=(source)->IP_WAN;	\
			(target)->IP_LAN=(source)->IP_LAN;	\
			(target)->IPADDR=(source)->IPADDR;	\
			(target)->Interface=(source)->Interface;	\
			(target)->INTERFACE_DATE=(source)->INTERFACE_DATE;	\
			(target)->SOFTWARE=(source)->SOFTWARE;	\
			(target)->FEE_TYPE=(source)->FEE_TYPE;	\
			(target)->SERVICEPROVIDER=(source)->SERVICEPROVIDER;	\
			(target)->IF_ZIYING=(source)->IF_ZIYING;	\
			(target)->IF_TUOGUAN=(source)->IF_TUOGUAN;	\
			(target)->HASOTHER=(source)->HASOTHER;	\
			(target)->SEAT_NO=(source)->SEAT_NO;	\
			(target)->PRO=(source)->PRO;	\

#endif
#ifndef CopyReqQryNetPartyLinkInfoEntity
#define CopyReqQryNetPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPartyLinkInfoEntity
#define CopyRspQryNetPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetPartyLinkInfoEntity
#define CopyRtnNetPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopySysNetMonitorActionAttrEntity
#define CopySysNetMonitorActionAttrEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ActionGroup_ID=(source)->ActionGroup_ID;	\
			(target)->MonitorAttr_ID=(source)->MonitorAttr_ID;	\
			(target)->MonitorAttrName=(source)->MonitorAttrName;	\

#endif
#ifndef CopyReqQryNetMonitorActionAttrEntity
#define CopyReqQryNetMonitorActionAttrEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorActionAttrEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMonitorActionAttrEntity
#define CopyRspQryNetMonitorActionAttrEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorActionAttrEntity(target,source);	\

#endif
#ifndef CopyRtnNetMonitorActionAttrEntity
#define CopyRtnNetMonitorActionAttrEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMonitorActionAttrEntity(target,source);	\

#endif
#ifndef CopySysNetModuleEntity
#define CopySysNetModuleEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonitorType_ID=(source)->MonitorType_ID;	\
			(target)->DeviceID=(source)->DeviceID;	\
			(target)->DeviceObjectID=(source)->DeviceObjectID;	\
			(target)->Name=(source)->Name;	\
			(target)->Description=(source)->Description;	\
			(target)->ModuleIndex=(source)->ModuleIndex;	\
			(target)->EntPhyIndex=(source)->EntPhyIndex;	\

#endif
#ifndef CopyReqQryNetModuleEntity
#define CopyReqQryNetModuleEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetModuleEntity(target,source);	\

#endif
#ifndef CopyRspQryNetModuleEntity
#define CopyRspQryNetModuleEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetModuleEntity(target,source);	\

#endif
#ifndef CopyRtnNetModuleEntity
#define CopyRtnNetModuleEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetModuleEntity(target,source);	\

#endif
#ifndef CopySysNetEventExprEntity
#define CopySysNetEventExprEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CNAME=(source)->CNAME;	\
			(target)->ENAME=(source)->ENAME;	\
			(target)->WarningLEVEL=(source)->WarningLEVEL;	\
			(target)->EventTypeID=(source)->EventTypeID;	\
			(target)->SubEventTypeID=(source)->SubEventTypeID;	\
			(target)->GIVEUPTIME=(source)->GIVEUPTIME;	\
			(target)->CONTROL=(source)->CONTROL;	\
			(target)->EXPR=(source)->EXPR;	\
			(target)->BRIEF=(source)->BRIEF;	\
			(target)->DISCRIPTION=(source)->DISCRIPTION;	\
			(target)->MSGGROUP_ID=(source)->MSGGROUP_ID;	\
			(target)->ADMINGROUP_ID=(source)->ADMINGROUP_ID;	\

#endif
#ifndef CopyReqQryNetEventExprEntity
#define CopyReqQryNetEventExprEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventExprEntity(target,source);	\

#endif
#ifndef CopyRspQryNetEventExprEntity
#define CopyRspQryNetEventExprEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventExprEntity(target,source);	\

#endif
#ifndef CopyRtnNetEventExprEntity
#define CopyRtnNetEventExprEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventExprEntity(target,source);	\

#endif
#ifndef CopySysNetEventTypeEntity
#define CopySysNetEventTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetEventTypeEntity
#define CopyReqQryNetEventTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetEventTypeEntity
#define CopyRspQryNetEventTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetEventTypeEntity
#define CopyRtnNetEventTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventTypeEntity(target,source);	\

#endif
#ifndef CopySysNetSubEventTypeEntity
#define CopySysNetSubEventTypeEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\

#endif
#ifndef CopyReqQryNetSubEventTypeEntity
#define CopyReqQryNetSubEventTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubEventTypeEntity(target,source);	\

#endif
#ifndef CopyRspQryNetSubEventTypeEntity
#define CopyRspQryNetSubEventTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubEventTypeEntity(target,source);	\

#endif
#ifndef CopyRtnNetSubEventTypeEntity
#define CopyRtnNetSubEventTypeEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetSubEventTypeEntity(target,source);	\

#endif
#ifndef CopySysNetEventLevelEntity
#define CopySysNetEventLevelEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->CName=(source)->CName;	\
			(target)->EName=(source)->EName;	\
			(target)->DISCRIPTION=(source)->DISCRIPTION;	\

#endif
#ifndef CopyReqQryNetEventLevelEntity
#define CopyReqQryNetEventLevelEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventLevelEntity(target,source);	\

#endif
#ifndef CopyRspQryNetEventLevelEntity
#define CopyRspQryNetEventLevelEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventLevelEntity(target,source);	\

#endif
#ifndef CopyRtnNetEventLevelEntity
#define CopyRtnNetEventLevelEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetEventLevelEntity(target,source);	\

#endif
#ifndef CopySysConfigLoginEntity
#define CopySysConfigLoginEntity(target,source)	\
			(target)->DataCenter=(source)->DataCenter;	\
			(target)->ID=(source)->ID;	\
			(target)->HasConfig=(source)->HasConfig;	\
			(target)->Authorization=(source)->Authorization;	\

#endif
#ifndef CopyReqConfigLoginEntity
#define CopyReqConfigLoginEntity(target,source)	\
			CopySysConfigLoginEntity(target,source);	\

#endif
#ifndef CopyRspQryConfigLoginEntity
#define CopyRspQryConfigLoginEntity(target,source)	\
			CopyErrorTypeEntity(target,source);	\

#endif
#ifndef CopyRspServerTypeEntity
#define CopyRspServerTypeEntity(target,source)	\
			(target)->IsMaster=(source)->IsMaster;	\

#endif
#ifndef CopySysServerExitEntity
#define CopySysServerExitEntity(target,source)	\
			(target)->Time=(source)->Time;	\
			(target)->Authorization=(source)->Authorization;	\

#endif
#ifndef CopySysNetCfgFileEntity
#define CopySysNetCfgFileEntity(target,source)	\
			(target)->ObjectID=(source)->ObjectID;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->CfgFileName=(source)->CfgFileName;	\

#endif
#ifndef CopyReqQryNetCfgFileEntity
#define CopyReqQryNetCfgFileEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCfgFileEntity(target,source);	\

#endif
#ifndef CopyRspQryNetCfgFileEntity
#define CopyRspQryNetCfgFileEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCfgFileEntity(target,source);	\

#endif
#ifndef CopyRtnNetCfgFileEntity
#define CopyRtnNetCfgFileEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetCfgFileEntity(target,source);	\

#endif
#ifndef CopySysFileGeneralOperEntity
#define CopySysFileGeneralOperEntity(target,source)	\
			(target)->FileName=(source)->FileName;	\
			(target)->Version=(source)->Version;	\
			(target)->SubVersion=(source)->SubVersion;	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->UserName=(source)->UserName;	\
			(target)->OperType=(source)->OperType;	\
			(target)->OperResult=(source)->OperResult;	\
			(target)->Comments=(source)->Comments;	\
			(target)->Offset=(source)->Offset;	\
			(target)->Length=(source)->Length;	\
			(target)->FileContent=(source)->FileContent;	\

#endif
#ifndef CopyReqQryFileGeneralOperEntity
#define CopyReqQryFileGeneralOperEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysFileGeneralOperEntity(target,source);	\

#endif
#ifndef CopyRspQryFileGeneralOperEntity
#define CopyRspQryFileGeneralOperEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysFileGeneralOperEntity(target,source);	\

#endif
#ifndef CopyRtnFileGeneralOperEntity
#define CopyRtnFileGeneralOperEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysFileGeneralOperEntity(target,source);	\

#endif
#ifndef CopySysNetBaseLineEntity
#define CopySysNetBaseLineEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->MANUFACTORY_ID=(source)->MANUFACTORY_ID;	\
			(target)->Name=(source)->Name;	\
			(target)->SerialUsed=(source)->SerialUsed;	\
			(target)->data=(source)->data;	\
			(target)->memo=(source)->memo;	\
			(target)->Flag=(source)->Flag;	\

#endif
#ifndef CopyReqQryNetBaseLineEntity
#define CopyReqQryNetBaseLineEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineEntity(target,source);	\

#endif
#ifndef CopyRspQryNetBaseLineEntity
#define CopyRspQryNetBaseLineEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineEntity(target,source);	\

#endif
#ifndef CopyRtnNetBaseLineEntity
#define CopyRtnNetBaseLineEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineEntity(target,source);	\

#endif
#ifndef CopySysNetBaseLineTaskEntity
#define CopySysNetBaseLineTaskEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->Name=(source)->Name;	\
			(target)->BaseLineIDList=(source)->BaseLineIDList;	\
			(target)->DeviceIDList=(source)->DeviceIDList;	\
			(target)->GenDate=(source)->GenDate;	\
			(target)->GenTime=(source)->GenTime;	\
			(target)->GenUser=(source)->GenUser;	\
			(target)->memo=(source)->memo;	\

#endif
#ifndef CopyReqQryNetBaseLineTaskEntity
#define CopyReqQryNetBaseLineTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineTaskEntity(target,source);	\

#endif
#ifndef CopyRspQryNetBaseLineTaskEntity
#define CopyRspQryNetBaseLineTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineTaskEntity(target,source);	\

#endif
#ifndef CopyRtnNetBaseLineTaskEntity
#define CopyRtnNetBaseLineTaskEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineTaskEntity(target,source);	\

#endif
#ifndef CopySysNetBaseLineResultEntity
#define CopySysNetBaseLineResultEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->BaseLineName=(source)->BaseLineName;	\
			(target)->DeviceObjID=(source)->DeviceObjID;	\
			(target)->DeviceIP=(source)->DeviceIP;	\
			(target)->Result=(source)->Result;	\
			(target)->GenDate=(source)->GenDate;	\
			(target)->GenTime=(source)->GenTime;	\
			(target)->GenUser=(source)->GenUser;	\
			(target)->Flag=(source)->Flag;	\

#endif
#ifndef CopyReqQryNetBaseLineResultEntity
#define CopyReqQryNetBaseLineResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineResultEntity(target,source);	\

#endif
#ifndef CopyRspQryNetBaseLineResultEntity
#define CopyRspQryNetBaseLineResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineResultEntity(target,source);	\

#endif
#ifndef CopyRtnNetBaseLineResultEntity
#define CopyRtnNetBaseLineResultEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetBaseLineResultEntity(target,source);	\

#endif
#ifndef CopySysNetPartyLinkStatusInfoEntity
#define CopySysNetPartyLinkStatusInfoEntity(target,source)	\
			(target)->MonDate=(source)->MonDate;	\
			(target)->MonTime=(source)->MonTime;	\
			(target)->SEAT_NO=(source)->SEAT_NO;	\
			(target)->IPADDR=(source)->IPADDR;	\
			(target)->Interface=(source)->Interface;	\
			(target)->status=(source)->status;	\

#endif
#ifndef CopyReqQryNetPartyLinkStatusInfoEntity
#define CopyReqQryNetPartyLinkStatusInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySearchKeyInfoEntity(target,source);	\
			CopySysNetPartyLinkStatusInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPartyLinkStatusInfoEntity
#define CopyRspQryNetPartyLinkStatusInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkStatusInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetPartyLinkStatusInfoEntity
#define CopyRtnNetPartyLinkStatusInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartyLinkStatusInfoEntity(target,source);	\

#endif
#ifndef CopySysMdbNetPartyLinkStatusInfoEntity
#define CopySysMdbNetPartyLinkStatusInfoEntity(target,source)	\
			(target)->SubcriberID=(source)->SubcriberID;	\
			CopySysNetPartyLinkStatusInfoEntity(target,source);	\

#endif
#ifndef CopySysNetMemberSDHLineInfoEntity
#define CopySysNetMemberSDHLineInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SeqNo=(source)->SeqNo;	\
			(target)->MemContractNo=(source)->MemContractNo;	\
			(target)->ApplyPerson=(source)->ApplyPerson;	\
			(target)->MonthlyRental=(source)->MonthlyRental;	\
			(target)->MemberNo=(source)->MemberNo;	\
			(target)->ParticipantName=(source)->ParticipantName;	\
			(target)->ClientManager=(source)->ClientManager;	\
			(target)->Bandwidth=(source)->Bandwidth;	\
			(target)->InterfaceType=(source)->InterfaceType;	\
			(target)->RemoteCircuit=(source)->RemoteCircuit;	\
			(target)->LocalCircuit=(source)->LocalCircuit;	\
			(target)->Remark=(source)->Remark;	\
			(target)->EndALineAddress=(source)->EndALineAddress;	\
			(target)->EndAContact=(source)->EndAContact;	\
			(target)->EndZLineAddress=(source)->EndZLineAddress;	\
			(target)->ContactName=(source)->ContactName;	\
			(target)->TELEPHONE=(source)->TELEPHONE;	\
			(target)->MOBILEPHONE=(source)->MOBILEPHONE;	\
			(target)->IPADDR=(source)->IPADDR;	\
			(target)->Interface=(source)->Interface;	\
			(target)->PROVINCE=(source)->PROVINCE;	\
			(target)->StartPortID=(source)->StartPortID;	\
			(target)->StartJump=(source)->StartJump;	\
			(target)->LINE_STATUS=(source)->LINE_STATUS;	\
			(target)->DataCenterID=(source)->DataCenterID;	\

#endif
#ifndef CopyReqQryNetMemberSDHLineInfoEntity
#define CopyReqQryNetMemberSDHLineInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMemberSDHLineInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetMemberSDHLineInfoEntity
#define CopyRspQryNetMemberSDHLineInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMemberSDHLineInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetMemberSDHLineInfoEntity
#define CopyRtnNetMemberSDHLineInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetMemberSDHLineInfoEntity(target,source);	\

#endif
#ifndef CopySysNetDDNLinkInfoEntity
#define CopySysNetDDNLinkInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->ClientName=(source)->ClientName;	\
			(target)->DDN_NO=(source)->DDN_NO;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->Bandwidth=(source)->Bandwidth;	\
			(target)->EndAAddress=(source)->EndAAddress;	\
			(target)->EndAContactName=(source)->EndAContactName;	\
			(target)->EndZAddress=(source)->EndZAddress;	\
			(target)->EndZContactName=(source)->EndZContactName;	\

#endif
#ifndef CopyReqQryNetDDNLinkInfoEntity
#define CopyReqQryNetDDNLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDDNLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetDDNLinkInfoEntity
#define CopyRspQryNetDDNLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDDNLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetDDNLinkInfoEntity
#define CopyRtnNetDDNLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetDDNLinkInfoEntity(target,source);	\

#endif
#ifndef CopySysNetPseudMemberLinkInfoEntity
#define CopySysNetPseudMemberLinkInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SeqNo=(source)->SeqNo;	\
			(target)->MemContractNo=(source)->MemContractNo;	\
			(target)->LineUsage=(source)->LineUsage;	\
			(target)->LocalCircuit=(source)->LocalCircuit;	\
			(target)->RemoteCircuit=(source)->RemoteCircuit;	\
			(target)->BusinessUnit=(source)->BusinessUnit;	\
			(target)->Bandwidth=(source)->Bandwidth;	\
			(target)->ApplyPerson=(source)->ApplyPerson;	\
			(target)->MonthlyRental=(source)->MonthlyRental;	\
			(target)->EndAAddress=(source)->EndAAddress;	\
			(target)->EndAContactName=(source)->EndAContactName;	\
			(target)->EndZAddress=(source)->EndZAddress;	\
			(target)->EndZContactName=(source)->EndZContactName;	\
			(target)->Telephone=(source)->Telephone;	\
			(target)->LineInfo=(source)->LineInfo;	\
			(target)->IPADDR=(source)->IPADDR;	\

#endif
#ifndef CopyReqQryNetPseudMemberLinkInfoEntity
#define CopyReqQryNetPseudMemberLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPseudMemberLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPseudMemberLinkInfoEntity
#define CopyRspQryNetPseudMemberLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPseudMemberLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetPseudMemberLinkInfoEntity
#define CopyRtnNetPseudMemberLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPseudMemberLinkInfoEntity(target,source);	\

#endif
#ifndef CopySysNetOuterDeviceInfoEntity
#define CopySysNetOuterDeviceInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->IPADDR=(source)->IPADDR;	\
			(target)->NAME=(source)->NAME;	\
			(target)->memo=(source)->memo;	\

#endif
#ifndef CopyReqQryOuterDeviceInfEntity
#define CopyReqQryOuterDeviceInfEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetOuterDeviceInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryOuterDeviceInfEntity
#define CopyRspQryOuterDeviceInfEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetOuterDeviceInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetOuterDeviceInfEntity
#define CopyRtnNetOuterDeviceInfEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetOuterDeviceInfoEntity(target,source);	\

#endif
#ifndef CopySysLocalPingResultInfoEntity
#define CopySysLocalPingResultInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SouIPADDR=(source)->SouIPADDR;	\
			(target)->SouNAME=(source)->SouNAME;	\
			(target)->TarIPADDR=(source)->TarIPADDR;	\
			(target)->TarNAME=(source)->TarNAME;	\
			(target)->PDateSta=(source)->PDateSta;	\
			(target)->PTimeSta=(source)->PTimeSta;	\
			(target)->ConnRate=(source)->ConnRate;	\

#endif
#ifndef CopyReqQryNetLocalPingResultInfoEntity
#define CopyReqQryNetLocalPingResultInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysLocalPingResultInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetLocalPingResultInfoEntity
#define CopyRspQryNetLocalPingResultInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysLocalPingResultInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetLocalPingResultInfoEntity
#define CopyRtnNetLocalPingResultInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysLocalPingResultInfoEntity(target,source);	\

#endif
#ifndef CopySysRomotePingResultInfoEntity
#define CopySysRomotePingResultInfoEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->SouIPADDR=(source)->SouIPADDR;	\
			(target)->SouNAME=(source)->SouNAME;	\
			(target)->TarIPADDR=(source)->TarIPADDR;	\
			(target)->TarNAME=(source)->TarNAME;	\
			(target)->PDateSta=(source)->PDateSta;	\
			(target)->PTimeSta=(source)->PTimeSta;	\
			(target)->ConnRate=(source)->ConnRate;	\
			(target)->TimeDlyMin=(source)->TimeDlyMin;	\
			(target)->TimeDlyMax=(source)->TimeDlyMax;	\
			(target)->TimeDlyAvg=(source)->TimeDlyAvg;	\

#endif
#ifndef CopyReqQryNetRomotePingResultInfoEntity
#define CopyReqQryNetRomotePingResultInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysRomotePingResultInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetRomotePingResultInfoEntity
#define CopyRspQryNetRomotePingResultInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysRomotePingResultInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetRomotePingResultInfoEntity
#define CopyRtnNetRomotePingResultInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysRomotePingResultInfoEntity(target,source);	\

#endif
#ifndef CopySysInternalTopologyEntity
#define CopySysInternalTopologyEntity(target,source)	\
			(target)->InfoType=(source)->InfoType;	\
			(target)->Node1_ID=(source)->Node1_ID;	\
			(target)->Node1_Info=(source)->Node1_Info;	\
			(target)->LinkInfo=(source)->LinkInfo;	\
			(target)->LinkState=(source)->LinkState;	\
			(target)->Node2_ID=(source)->Node2_ID;	\
			(target)->Node2_Info=(source)->Node2_Info;	\

#endif
#ifndef CopyReqQrySysInternalTopologyEntity
#define CopyReqQrySysInternalTopologyEntity(target,source)	\
			CopySysInternalTopologyEntity(target,source);	\

#endif
#ifndef CopyRspQrySysInternalTopologyEntity
#define CopyRspQrySysInternalTopologyEntity(target,source)	\
			CopySysInternalTopologyEntity(target,source);	\

#endif
#ifndef CopyRtnSysInternalTopologyEntity
#define CopyRtnSysInternalTopologyEntity(target,source)	\
			CopySysInternalTopologyEntity(target,source);	\

#endif
#ifndef CopySysNetPartylinkMonthlyRentEntity
#define CopySysNetPartylinkMonthlyRentEntity(target,source)	\
			(target)->ID=(source)->ID;	\
			(target)->LineName=(source)->LineName;	\
			(target)->DDN_NO=(source)->DDN_NO;	\
			(target)->ServiceProvider=(source)->ServiceProvider;	\
			(target)->MonthlyRental=(source)->MonthlyRental;	\
			(target)->Remark=(source)->Remark;	\

#endif
#ifndef CopyReqQryNetPartylinkMonthlyRentEntity
#define CopyReqQryNetPartylinkMonthlyRentEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartylinkMonthlyRentEntity(target,source);	\

#endif
#ifndef CopyRspQryNetPartylinkMonthlyRentEntity
#define CopyRspQryNetPartylinkMonthlyRentEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartylinkMonthlyRentEntity(target,source);	\

#endif
#ifndef CopyRtnNetPartylinkMonthlyRentEntity
#define CopyRtnNetPartylinkMonthlyRentEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetPartylinkMonthlyRentEntity(target,source);	\

#endif
#ifndef CopySysNetNonPartyLinkInfoEntity
#define CopySysNetNonPartyLinkInfoEntity(target,source)	\
			CopySysNetPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyReqQryNetNonPartyLinkInfoEntity
#define CopyReqQryNetNonPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetNonPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRspQryNetNonPartyLinkInfoEntity
#define CopyRspQryNetNonPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetNonPartyLinkInfoEntity(target,source);	\

#endif
#ifndef CopyRtnNetNonPartyLinkInfoEntity
#define CopyRtnNetNonPartyLinkInfoEntity(target,source)	\
			CopyOperateTypeRefEntity(target,source);	\
			CopySysNetNonPartyLinkInfoEntity(target,source);	\

#endif

#endif


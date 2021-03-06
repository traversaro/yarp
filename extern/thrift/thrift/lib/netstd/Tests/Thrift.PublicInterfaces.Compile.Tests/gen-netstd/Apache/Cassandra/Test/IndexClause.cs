/**
 * Autogenerated by Thrift Compiler (0.14.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.Extensions.Logging;
using Thrift;
using Thrift.Collections;
using System.ServiceModel;
using System.Runtime.Serialization;

using Thrift.Protocol;
using Thrift.Protocol.Entities;
using Thrift.Protocol.Utilities;
using Thrift.Transport;
using Thrift.Transport.Client;
using Thrift.Transport.Server;
using Thrift.Processor;


#pragma warning disable IDE0079  // remove unnecessary pragmas
#pragma warning disable IDE1006  // parts of the code use IDL spelling

namespace Apache.Cassandra.Test
{

  [DataContract(Namespace="")]
  public partial class IndexClause : TBase
  {

    [DataMember(Order = 0)]
    public List<global::Apache.Cassandra.Test.IndexExpression> Expressions { get; set; }

    [DataMember(Order = 0)]
    public byte[] Start_key { get; set; }

    [DataMember(Order = 0)]
    public int Count { get; set; }

    public IndexClause()
    {
      this.Count = 100;
    }

    public IndexClause(List<global::Apache.Cassandra.Test.IndexExpression> expressions, byte[] start_key, int count) : this()
    {
      this.Expressions = expressions;
      this.Start_key = start_key;
      this.Count = count;
    }

    public IndexClause DeepCopy()
    {
      var tmp46 = new IndexClause();
      if((Expressions != null))
      {
        tmp46.Expressions = this.Expressions.DeepCopy();
      }
      if((Start_key != null))
      {
        tmp46.Start_key = this.Start_key.ToArray();
      }
      tmp46.Count = this.Count;
      return tmp46;
    }

    public async global::System.Threading.Tasks.Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        bool isset_expressions = false;
        bool isset_start_key = false;
        bool isset_count = false;
        TField field;
        await iprot.ReadStructBeginAsync(cancellationToken);
        while (true)
        {
          field = await iprot.ReadFieldBeginAsync(cancellationToken);
          if (field.Type == TType.Stop)
          {
            break;
          }

          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.List)
              {
                {
                  TList _list47 = await iprot.ReadListBeginAsync(cancellationToken);
                  Expressions = new List<global::Apache.Cassandra.Test.IndexExpression>(_list47.Count);
                  for(int _i48 = 0; _i48 < _list47.Count; ++_i48)
                  {
                    global::Apache.Cassandra.Test.IndexExpression _elem49;
                    _elem49 = new global::Apache.Cassandra.Test.IndexExpression();
                    await _elem49.ReadAsync(iprot, cancellationToken);
                    Expressions.Add(_elem49);
                  }
                  await iprot.ReadListEndAsync(cancellationToken);
                }
                isset_expressions = true;
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            case 2:
              if (field.Type == TType.String)
              {
                Start_key = await iprot.ReadBinaryAsync(cancellationToken);
                isset_start_key = true;
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            case 3:
              if (field.Type == TType.I32)
              {
                Count = await iprot.ReadI32Async(cancellationToken);
                isset_count = true;
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            default: 
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              break;
          }

          await iprot.ReadFieldEndAsync(cancellationToken);
        }

        await iprot.ReadStructEndAsync(cancellationToken);
        if (!isset_expressions)
        {
          throw new TProtocolException(TProtocolException.INVALID_DATA);
        }
        if (!isset_start_key)
        {
          throw new TProtocolException(TProtocolException.INVALID_DATA);
        }
        if (!isset_count)
        {
          throw new TProtocolException(TProtocolException.INVALID_DATA);
        }
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public async global::System.Threading.Tasks.Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
    {
      oprot.IncrementRecursionDepth();
      try
      {
        var struc = new TStruct("IndexClause");
        await oprot.WriteStructBeginAsync(struc, cancellationToken);
        var field = new TField();
        if((Expressions != null))
        {
          field.Name = "expressions";
          field.Type = TType.List;
          field.ID = 1;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          {
            await oprot.WriteListBeginAsync(new TList(TType.Struct, Expressions.Count), cancellationToken);
            foreach (global::Apache.Cassandra.Test.IndexExpression _iter50 in Expressions)
            {
              await _iter50.WriteAsync(oprot, cancellationToken);
            }
            await oprot.WriteListEndAsync(cancellationToken);
          }
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        if((Start_key != null))
        {
          field.Name = "start_key";
          field.Type = TType.String;
          field.ID = 2;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteBinaryAsync(Start_key, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        field.Name = "count";
        field.Type = TType.I32;
        field.ID = 3;
        await oprot.WriteFieldBeginAsync(field, cancellationToken);
        await oprot.WriteI32Async(Count, cancellationToken);
        await oprot.WriteFieldEndAsync(cancellationToken);
        await oprot.WriteFieldStopAsync(cancellationToken);
        await oprot.WriteStructEndAsync(cancellationToken);
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override bool Equals(object that)
    {
      if (!(that is IndexClause other)) return false;
      if (ReferenceEquals(this, other)) return true;
      return TCollections.Equals(Expressions, other.Expressions)
        && TCollections.Equals(Start_key, other.Start_key)
        && System.Object.Equals(Count, other.Count);
    }

    public override int GetHashCode() {
      int hashcode = 157;
      unchecked {
        if((Expressions != null))
        {
          hashcode = (hashcode * 397) + TCollections.GetHashCode(Expressions);
        }
        if((Start_key != null))
        {
          hashcode = (hashcode * 397) + Start_key.GetHashCode();
        }
        hashcode = (hashcode * 397) + Count.GetHashCode();
      }
      return hashcode;
    }

    public override string ToString()
    {
      var sb = new StringBuilder("IndexClause(");
      if((Expressions != null))
      {
        sb.Append(", Expressions: ");
        Expressions.ToString(sb);
      }
      if((Start_key != null))
      {
        sb.Append(", Start_key: ");
        Start_key.ToString(sb);
      }
      sb.Append(", Count: ");
      Count.ToString(sb);
      sb.Append(')');
      return sb.ToString();
    }
  }

}
